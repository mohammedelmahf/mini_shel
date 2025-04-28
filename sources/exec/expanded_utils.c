/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:17:15 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/28 12:35:54 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *handle_squotes(char *str , size_t *i)
{
    size_t  start;

    start = *i;

    (*i)++;
    while(str[*i] && str[*i] != '\'')
        (*i)++;
    (*i)++;
    return(ft_substr(str , start , *i - start));
}

char   *handle_dquotes(char *str , size_t *i)
{
    char *ret;

    ret = ft_strdup("");
    (*i)++;
    while(str[*i] != '"')
    {
        if(str[*i] == '$')
            ret = ft_strjoin_f(ret , handle_dollar(str , i));
        else
            ret = ft_strjoin_f(ret , handle_dquotes_str(str , i));
    }
    (*i)++;
    return(ft_strjoin_f(ret , ft_strdup("\"")));
}

char    *handle_dquotes_str(char *str , size_t *i)
{
    char *ret;
    size_t start;

    start = *i;
    while(str[*i] != '$' && str[*i] != '"')
        (*i)++;
    ret = ft_substr(str , start , *i - start);
    return(ret);
}

