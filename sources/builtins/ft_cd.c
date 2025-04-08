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

int ft_cd(char *path)
{
    char * home ;
    //char *oldpwd;
    
    if(!path)
    {
        home  = getenv("HOME");
        if(!home)
        {
            //strr ??!! att bb !!
            printf("minishell: cd: HOME not set\n");
        }
        path = home;
    }
    if(chdir(path) == - 1)
    {
        perror("minishell: cd")
        return 1;
    }
    return 0;
}