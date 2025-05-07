/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:30:01 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/07 12:58:50 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int exec_builtins(char **args)
{
//     int i = 0;
//     while (args[i])
//   {
//     printf("%s\n" ,args[i]);
//     i++;
//   }
//   printf ("hni kharj \n");
//   exit(1);
    if(ft_strcmp(args[0] , "echo") == 0)
        return (ft_echo(args));
    else  if(ft_strcmp(args[0] , "cd") == 0)
        return (ft_cd(args));
    else if(ft_strcmp(args[0] , "pwd") == 0)
        return (ft_pwd());
    else if(ft_strcmp(args[0] , "export") == 0)
        return (ft_export(args));
    else if(ft_strcmp(args[0] , "unset") == 0)
        return (ft_unset(args));
    else if(ft_strcmp(args[0] , "env") == 0)
        return (ft_env());
    ft_exit(args);
    return 0;
}

bool    is_builtin(char *arg)
{
	if (!arg)
		return (false);
    
	if (!ft_strcmp(arg, "echo")
        || !ft_strcmp(arg, "cd")
		|| !ft_strcmp(arg, "exit")
		|| !ft_strcmp(arg, "pwd")
		|| !ft_strcmp(arg, "export")
		|| !ft_strcmp(arg, "unset")
		|| !ft_strcmp(arg, "env"))
		return (true);
	return (false);
}