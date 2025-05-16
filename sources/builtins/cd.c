/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:07 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/16 09:16:55 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cd_err_msg(char *msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	g_data.exit_s = 1;
	return (1);
}

int	cd_err_msg_1(void)
{
	ft_putstr_fd("minishell: cd:", 2);
	ft_putstr_fd(" too many arguments\n", 2);
	g_data.exit_s = 1;
	return (1);
}

int	ft_cd(char **path)
{
	char	*new_pwd;

	if (path[0] && !path[1])
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		g_data.exit_s = 1;
		return (0);
	}
	if (path[2])
		return (cd_err_msg_1());
	if (chdir(path[1]) != 0)
		return (cd_err_msg(path[1]));
	update_oldpwd("OLDPWD", get_envlst_value("PWD"), true);
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
	{
		perror("minishell: cd: error retrieving current directory");
		g_data.exit_s = 1;
		return (1);
	}
	update_oldpwd("PWD", new_pwd, true);
	free(new_pwd);
	g_data.exit_s = 0;
	return (0);
}
