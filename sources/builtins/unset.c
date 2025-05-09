/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:26 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/09 09:21:50 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void msg_err(char *s)
{
    ft_putstr_fd ("minishell: export:" , 2);
    ft_putstr_fd (s , 2);
    ft_putstr_fd (": not a valid identifier\n", 2);
    data.exit_s = 1;
}

void ft_unset_help(char *key)
{
    t_env *current;
    t_env *prev;

    prev = NULL;
    current = data.envlst;

    while(current)
    {
        if(!ft_strcmp( key , current->key))
        {
            if(prev)
                prev->next = current->next;
            else
                data.envlst = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int ft_unset(char **s)
{   
    bool err;
    int i;
    err = false;    
    
    i = 1;
    if(!s)
        return 0;
    while(s[i])
    {
        if (!parsing_key(s[i]))
        {
            msg_err(s[i]);
            err = true;
        }
        else
            ft_unset_help(garbage_collector(extract_key(s[i]) , false));
        i++;
    }
    return (err);
}