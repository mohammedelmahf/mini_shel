/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:28:33 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/08 10:46:42 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *extract_key(char *str)
{
    size_t i;
    
    i = 0;
    while(str[i])
    {
        if(str[i] == '=')
            return (garbage_collector(ft_substr(str , 0 ,i) , false));
        i++;
    }
    return(ft_strdup(str));
}

char    *extract_value(char *str)
{
    size_t i;
    
    i = 0;
    while(str[i])
    {
        if(str[i] == '=')
        {
            i++;
            return (garbage_collector(ft_substr(str , i ,ft_strlen(str) - i) , false));
        }
        i++;
    }
    return(NULL);
}

void    init_envlst(void)
{
    int     i;
    char    **environ;
    char    *key;
    char    *value;

    environ = data.environ;
    if(!environ)
        return ;
    i = 0;
    while(environ[i])
    {
        key = extract_key(environ[i]);
        value = extract_value(environ[i]);
        update_envlst(key, value, true);
        i++;
    }
}