/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:41:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/07 10:22:36 by maelmahf         ###   ########.fr       */
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

char    **allocater(char *str , char **strs)
{
    size_t  start;
    size_t  i;
    size_t  j;

    i =0;
    j = 0;
    while(str[i])
    {
        if(str[i] != ' ')
        {
            start = i;
            skip_word(str , &i);
            strs[j] = ft_calloc(i - start + 1 , sizeof(char));
            if(!strs[j])
                return (NULL);
            j++;
        }
        while(str[i] && str[i] == ' ')
            i++;
    }
    return (strs);
}

void  word_filler(const char *str , char **strs , size_t *i , size_t j)
{
	char	quotes;
	size_t	k;

	k = 0;
	while (str[(*i)] && str[(*i)] != ' ')
	{
		if (str[(*i)] != '\'' && str[(*i)] != '"')
			strs[j][k++] = str[(*i)++];
		else
		{
			quotes = str[(*i)++];
			strs[j][k++] = quotes;
			while (str[(*i)] != quotes)
				strs[j][k++] = str[(*i)++];
			strs[j][k++] = str[(*i)++];
		}
	}
}  

char    **filler(char *str , char **strs)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    while(str[i] && strs[j])
    {
        if(str[i] != ' ')
        {
            word_filler(str , strs , &i , j);
            j++;
        }
        while(str[i] && str[i] == ' ')
            i++;
    }
    return (strs);
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
    if(!strs || !count)
        return (free_char2(tofree) , NULL);
    return (filler(str , strs));
}