/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:41:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/29 10:03:09 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
}