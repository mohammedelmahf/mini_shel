/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:30:27 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/15 09:16:17 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_child(t_node *node)
{
	int	fork_pid;
	int	status;

	g_data.signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
		child_exec_logic(node);
	waitpid(fork_pid, &status, 0);
	g_data.signint_child = false;
	return (get_exit_status(status));
}

static int	handle_exec_logic(t_node *node, bool pipe)
{
	int	status;

	if (!node->expanded_args || !node->expanded_args[0]
		|| node->expanded_args[0][0] == '\0')
	{
		//ft_putstr_fd("minishell: command not found\n", 2);
		status = check_redirections(node);
		reset_std(pipe);
		return (ENO_COMMAND_NOT_FOUND);
	}
	if (is_builtin(node->expanded_args[0]))
	{
		status = check_redirections(node);
		if (status != ENO_SUCCESS)
		{
			reset_std(pipe);
			return (ENO_GENERAL);
		}
		status = exec_builtins(node->expanded_args);
		reset_std(pipe);
		return (status);
	}
	return (exec_child(node));
}

int	exec_simple_cmd(t_node *node, bool pipe)
{
	int	status;

	node->expanded_args = expand_args(node->args);
	if (!node->expanded_args)
	{
		//ft_putstr_fd("Command not found\n", 2);
		status = check_redirections(node);
		reset_std(pipe);
		return (ENO_GENERAL);
	}
	return (handle_exec_logic(node, pipe));
}
