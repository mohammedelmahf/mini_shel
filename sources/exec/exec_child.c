/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:48:44 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/26 09:19:45 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_special_commands(char *cmd)
{
	if (ft_strcmp(cmd, ".") == 0 || ft_strcmp(cmd, "..") == 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		clean_all();
		exit(127);
	}
}

void	handle_invalid_path(char *path)
{
	DIR	*dir;

	if (access(path, F_OK) == 0)
	{
		dir = opendir(path);
		if (dir)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(path, 2);
			ft_putstr_fd(": Is a directory\n", 2);
			closedir(dir);
			clean_all();
			exit(126);
		}
	}
	else
	{
		perror("minishell");
		clean_all();
		exit(127);
	}
}

void	child_exec_logic(t_node *node)
{
	t_path	path_status;
	int		status;

	status = check_redirections(node);
	if (status != ENO_SUCCESS)
	{
		clean_all();
		exit(ENO_GENERAL);
	}
	handle_special_commands(node->expanded_args[0]);
	path_status = get_path(node->expanded_args[0]);
	if (path_status.err.num != ENO_SUCCESS)
	{
		status = ft_err_msg(path_status.err);
		clean_all();
		exit(status);
	}
	handle_invalid_path(path_status.path);
	if (execve(path_status.path, node->expanded_args, g_data.environ) == -1)
	{
		clean_all();
		exit(status);
	}
}

int	check_redirections(t_node *node)
{
	t_io_node	*tmp_io;
	int			status;

	tmp_io = node->io_list;
	while (tmp_io)
	{
		if (tmp_io->type == IO_IN && exec_in(tmp_io, &status) != ENO_SUCCESS)
			return (status);
		else if (tmp_io->type == IO_OUT && exec_out(tmp_io,
				&status) != ENO_SUCCESS)
			return (status);
		else if (tmp_io->type == IO_APPEND && exec_append(tmp_io,
				&status) != ENO_SUCCESS)
			return (status);
		else if (tmp_io->type == IO_HEREDOC)
		{
			dup2(tmp_io->here_doc, 0);
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
	dup2(g_data.stdin, 0);
	dup2(g_data.stdout, 1);
}
