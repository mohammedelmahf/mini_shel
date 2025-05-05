/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:30:27 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/05 14:45:50 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int check_redirections(t_node *node)
{
    t_io_node *tmp_io;
    int status;
    
    tmp_io = node->io_list;
    while(tmp_io)
    {
        if(node->type == IO_IN && exec_in(tmp_io , &status) != ENO_SUCCESS)
            return (status);
        else if(node->type == IO_OUT  && exec_out(tmp_io , &status) != ENO_SUCCESS)
            return (status);
        else if(node->type == IO_APPEND  && exec_append(tmp_io , &status) != ENO_SUCCESS)
            return (status);
        else if(node->type == IO_HEREDOC)
        {
            dup2(tmp_io->here_doc , 0);
            close(tmp_io->here_doc);
        }
        tmp_io = tmp_io->next;
    }
    return (ENO_SUCCESS);
}

void	reset_std(bool pipd)
{
	if (pipd)
		return ;
	dup2(data.stdin, 0);
	dup2(data.stdout, 1);
}

int exec_child(t_node *node)
{
    t_path path_status;
    int fork_pid = 0;
    int status;

    data.signint_child = true;

    if(!fork_pid)
    {
        status = check_redirections(node);
        if(status != ENO_SUCCESS)
        {
            clean_all();
            exit(ENO_GENERAL);
        }
        path_status = get_path((node->expanded_args[0]));
        if(path_status.err.num != ENO_SUCCESS)
        {
            status = ft_err_msg(path_status.err);
            clean_all();
            exit(status);
        }
        if(execve(path_status.path ,node->expanded_args , data.environ) == -1)
        {
            clean_all();
            exit(1);
        }
    }
        waitpid(fork_pid ,&status , 0);
        data.signint_child = false;
        return (get_exit_status (status));
}

int  exec_simple_cmd(t_node *node, bool pipe)
{
    int stauts;
    if (!node->expanded_args)
    {
        printf("Command not found\n");
        stauts = check_redirections(node);
        reset_std(pipe);
        return (stauts && ENO_GENERAL);
    }
    else if (is_builtin((node->expanded_args)[0]))
    {
        stauts = check_redirections(node);
        if(stauts != ENO_SUCCESS)
        {
           reset_std(pipe);
            return ( stauts && ENO_GENERAL);       
        }
        stauts = exec_builtins(node->expanded_args);
        reset_std(pipe);
        return (stauts);       
    }
    else
        return (exec_child(node));
}