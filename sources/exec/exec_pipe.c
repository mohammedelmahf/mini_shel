#include "../../includes/minishell.h"


void   exec_pipe_child(t_node* tree , int pipfd[2] ,t_direction derection)
{
    int status;

    if(derection == TD_LEFT)
    {
        close(pipfd[0]);
		dup2(pipfd[1], STDIN_FILENO);
		close(pipfd[1]);
    }
    else if(derection == TD_RIGHT)
    {
        close(pipfd[1]);
		dup2(pipfd[0], STDIN_FILENO);
		close(pipfd[0]);
    }
    status = exec_node(tree , true);
    clean_all();
    exit(status);
}

int	get_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}


int exec_pipe(t_node *tree)
{
	int status_l = 0;
	int status_r = 0;
	int pipfd[2];
	int pid_l;
    int pid_r;

	data.signint_child= true;
	if (pipe(pipfd) == -1)
		return (ENO_GENERAL);

	pid_l = fork();
	if (pid_l == 0)
		exec_pipe_child(tree->left, pipfd, TD_LEFT);

	pid_r = fork();
	if (pid_r == 0)
		exec_pipe_child(tree->right, pipfd, TD_RIGHT);

	close(pipfd[0]);
	close(pipfd[1]);

	waitpid(pid_l, &status_l, 0);
	waitpid(pid_r, &status_r, 0);

	data.signint_child = false;
	return get_exit_status(status_r);
}

// int exec_node( t_node *node , bool piped)
// {
//     if(!node)
//         return 1;

//     if(node->type == N_PIPE)
//         return(exec_pipe(node));

// }