<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:12:08 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/08 12:12:09 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../../includes/minishell.h"
=======
#include "../../includes/minishell.h"
>>>>>>> 2f97751 (iel-asef : create cmd cd)

int ft_cd(char **args)
{
    char *path;
    char *oldpwd;
    char *cwd;

    if (!args[1])
        path = ft_getenv("HOME");
    else if (!ft_strcmp(args[1], "-"))
        path = ft_getenv("OLDPWD");
    else
        path = args[1];

    if (!path)
    {
        printf("minishell: cd: path not set\n");
        return (1);
    }

    oldpwd = ft_getenv("PWD");
    if (chdir(path) == -1)
    {
        perror("minishell: cd");
        return (1);
    }

    update_envlst("OLDPWD", oldpwd, true);
    cwd = getcwd(NULL, 0);
    update_envlst("PWD", cwd, true);
    free(cwd);

    return (0);
}
