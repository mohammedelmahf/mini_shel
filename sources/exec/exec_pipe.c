/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:30:13 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/07 11:27:06 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void   exec_pipe_child(t_node* tree , int pipfd[2] ,t_direction derection)
{
    int status = 0;

    if(derection == TD_LEFT)
    {
        close(pipfd[0]);
		dup2(pipfd[1], STDOUT_FILENO);
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
	int status;
	int pipfd[2];
	int pid_l;
    int pid_r;

	data.signint_child= true;
	pipe(pipfd);
	
	pid_l = fork();
	if (!pid_l)
		exec_pipe_child(tree->left, pipfd, TD_LEFT);
	else 
	{
		pid_r = fork();
		if(!pid_r)
			exec_pipe_child(tree->right, pipfd, TD_RIGHT);
		else
		{
			close(pipfd[0]);
			close(pipfd[1]);
			waitpid(pid_l, &status, 0);
			waitpid(pid_r, &status, 0);
			data.signint_child = false;
			return (get_exit_status(status));
		}
	}
	return (ENO_GENERAL);
}

int exec_node( t_node *tree , bool piped)
{
	int status;
    
	if(!tree)
        return 1;
    if(tree->type == N_PIPE)
        return(exec_pipe(tree));
	else if (tree->type == N_AND)
	{
		status = exec_node(tree->left, false);
		if (status == ENO_SUCCESS)
			return (exec_node(tree->right, false));
		return (status);
	}
	else if (tree->type == N_OR)
	{
		status = exec_node(tree->left, false);
		if (status == ENO_SUCCESS)
			return (status);
		return (exec_node(tree->right, false));
	}
	else
		return(exec_simple_cmd(tree, piped));
	
	return (ENO_GENERAL);
}