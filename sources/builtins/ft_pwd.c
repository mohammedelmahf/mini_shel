<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:12:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/08 12:12:14 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../../includes/minishell.h"
=======
#include  "../../includes/minishell.h"
>>>>>>> 2f97751 (iel-asef : create cmd cd)

int  ft_pwd (void)
{
    char pwd[PATH_MAX];
    
    if(getcwd(pwd , PATH_MAX))
    {
        printf("%s\n", pwd);
        return (0);
    }
    else
    {
        perror("pwd");
        return (1);
    }
}