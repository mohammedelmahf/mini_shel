/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:07 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/10 12:20:55 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int cd_err_msg(char *msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	g_data.exit_s = 1;
	return (1);
}

int cd_err_msg_1(void)
{
	ft_putstr_fd("minishell: cd:", 2);
	ft_putstr_fd(" too many arguments\n", 2);
	g_data.exit_s = 1;
	return (1);
}

int ft_cd(char **path)
{
	// char buffer[PATH_MAX];
	
	// if(getcwd(buffer ,sizeof(buffer)))
	// 	g_data.save_oldpwd = ft_strdup(buffer);
	if (path[0] && !path[1])
	{
		printf("minishell: cd: HOME not set\n");
		g_data.exit_s = 1;
		return (0);
	}
	if(path[2])
		return (cd_err_msg_1());
	if (chdir(path[1]) != ENO_SUCCESS )
		return (cd_err_msg(path[1]));
	g_data.exit_s = 0;
	return (0);
}