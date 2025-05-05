/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:10 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/03 14:31:11 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int parsinge_echo(char *str)
{
	int i = 1;

	if (str[0] != '-')
		return (0);
	if (!str[1])
    	return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(char **str)
{
    int i;
    int flag_n;

    i = 1;
    flag_n = 0;
    while(str[i] != NULL && (parsinge_echo(str[i]) == 1))
    {
        flag_n = 1;
        i++;
    }
    while(str[i])
    {
         ft_putstr_fd(str[i] , 1);
         if(str[i + 1])
            ft_putstr_fd(" " , 1);
        i++;
    }
    if(flag_n== 0)
        ft_putstr_fd("\n" , 1);
    return (0);
}
