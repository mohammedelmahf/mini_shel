/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:07 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/07 13:07:36 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int change_pwd(void)
{
	char *cwd;

	cwd = getcwd(NULL , 0);
	if(!cwd)
		return (1);
	update_envlst("PWD" ,cwd ,false);
	return (0);
}

int	cd_home(void)
{
	char	*home;
	
	update_envlst("OLDPWD" ,get_envlst_value("PWD") , false);
	home = get_envlst_value("HOME");
	if(!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(home) == ENO_SUCCESS)
	{
		update_envlst("PWD" ,home ,false);
		return (0);
	}
	return (1);	
}

int cd_err_msg(char *msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (1);
}

int cont_arg(char **arg)
{
	int i;
	i = 0;
	while(arg[i])
		i++;
	return i;	
}

int ft_cd(char **path)
{
	int argc;

	argc = cont_arg(path);
	if (argc == 1)
		return cd_home();
	if (argc > 2) 
		return (cd_err_msg(path[2]));
	if (chdir(path[1]) != ENO_SUCCESS )
		return (cd_err_msg(path[1]));
	update_envlst("OLDPWD" ,get_envlst_value("PWD") , false);
	return (change_pwd());
}