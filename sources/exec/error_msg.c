/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:30:08 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/11 09:13:28 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_err_msg(t_err err)
{
	if (err.msg == ERRMSG_CMD_NOT_FOUND)
		return (
			ft_putstr_fd("minishell: ", 2),
			ft_putstr_fd(err.cause, 2),
			ft_putstr_fd(": command not found", 2),
			ft_putstr_fd("\n",2),
			g_data.exit_s = 127
		);
	else if (err.msg == ERRMSG_NO_SUCH_FILE)
		return (
			ft_putstr_fd("minishell: ", 2),
			ft_putstr_fd(err.cause , 2),
			ft_putstr_fd(": No such file or directory", 2),
			ft_putstr_fd("\n", 2),
			g_data.exit_s = 127
		);
	else if (err.msg == ERRMSG_PERM_DENIED)
		return (
			ft_putstr_fd("minishell: ", 2),
			ft_putstr_fd(err.cause, 2),
			ft_putstr_fd(": Permission denied", 2),
			ft_putstr_fd("\n", 2),
			err.num
		);
	else if (err.msg == ERRMSG_AMBIGUOUS)
		return (
			ft_putstr_fd("minishell: ", 2),
			ft_putstr_fd(err.cause, 2),
			ft_putstr_fd(": ambiguous redirect", 2),
			err.num
		);
	else if (err.msg == ERRMSG_TOO_MANY_ARGS)
		return (
			ft_putstr_fd("minishell: exit: too many arguments\n", 2),
			g_data.exit_s = 1,
			err.num
		);
	else if (err.msg == ERRMSG_NUMERIC_REQUI)
		return (
			ft_putstr_fd("minishell: ", 2),
			ft_putstr_fd(err.cause, 2),
			ft_putstr_fd(": numeric argument required", 2),
			ft_putstr_fd("\n", 2),
			err.num
		);
	return (0);
}
