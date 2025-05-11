/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:23 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/11 11:07:14 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_pwd(void)
{
    char pwd[PATH_MAX];
    char *pwd_env;
    
    if (getcwd(pwd, PATH_MAX))
    {
        printf("%s\n", pwd);
        return (0);
    }
    else
    {
        pwd_env = get_envlst_value("PWD");
        if (pwd_env)
        {
            printf("%s\n", pwd_env);
            return (0);
        }
        else
        {
            perror("pwd");
            return (1);
        }
    }      
}