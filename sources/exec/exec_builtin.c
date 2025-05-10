/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:30:01 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/10 17:28:30 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int exec_builtins(char **args)
{
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
        return (ft_env(args));
    else if(ft_strcmp(args[0] , "exit") == 0)
        return(ft_exit(args));
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