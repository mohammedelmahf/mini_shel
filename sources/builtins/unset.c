/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:26 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/10 18:38:30 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int parsing_key(char *str)
{
	int i = 0;

	if (!str || (!ft_isalpha(str[i]) && str[i] != '_'))
		return 0;

	while (str[i] && str[i] != '=' && !(str[i] == '+' && str[i + 1] == '='))
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return 0;
		i++;
	}
	return 1;
}

void msg_err(char *s)
{
    ft_putstr_fd ("minishell: export:" , 2);
    ft_putstr_fd (s , 2);
    ft_putstr_fd (": not a valid identifier\n", 2);
    g_data.exit_s = 1;
}

void ft_unset_help(char *key)
{
    t_env *current;
    t_env *prev;

    prev = NULL;
    current = g_data.envlst;

    while(current)
    {
        if(!ft_strcmp( key , current->key))
        {
            if(prev)
                prev->next = current->next;
            else
                g_data.envlst = current->next;
            // free(current);
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