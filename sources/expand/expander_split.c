/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:41:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/29 15:25:52 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    skip_word(char *str , size_t *i)
{
    char quotes;

    while(str[*i] && str[*i] != ' ')
    {
        if(str[*i] !='\'' && str[*i] != '"')
            (*i)++;
        else
        {
            quotes = str[(*i)++];
            while(str[*i] && str[*i] != quotes)
                (*i)++;
            (*i)++;
        }
    }
}

char    **expander_split(char *str)
{
    size_t  count;
    char    **tofree;
    char    **strs;
    size_t  i;
    
    if(!str)
        return (NULL);
    i = 0;
    count = 0;
    while(str[i])
    {
        if(str[i] != ' ' && ++count)
            skip_word(str , &i);
        while(str[i] && str[i] == ' ')
            i++;
    }
    strs = ft_calloc(count +1 , sizeof(char *));
    tofree = strs;
    strs = allocater(str , strs);
    if(!strs || !count);
        return (free_spliter(tofree) , NULL);
    return (filler(str , strs));
}