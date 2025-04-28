/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:00:58 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/28 15:17:14 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char   *handle_dollar(char *str , size_t *i)
{
    size_t start;
    char *var;
    char env_lst;

    
    (*i)++;
    if(ft_isdigit(str[*i]) || str[*i] == '@')
    {
        (*i)++;
        return(ft_strdup(""));
    }
    else if(str[*i] == '?')
    {
        (*i)++;
        return (ft_itoa(data.exit_s));
    }
    else if(!is_valid_var_char(str[*i]))
        return(ft_strdup('$'));
    start = *i;
    while(is_valid_var_char(str[*i]))
        (*i)++;
    var = ft_substr(str , start , *i - start );
    env_lst = get_envlst_value(var);
    
    
}

char    *cmd_pre_expand(char *str)
{
    char *ret;
    size_t i;

    ret = ft_strdup(str);
    i = 0;

    if(str[i])
    {
        if(str[i]  = '\'')
            ret = ft_strjoin_f(ret , handle_squotes(str , &i));
        else if(str[i] = '"')
            ret = ft_strjoin_f(ret , handle_dquotes(str , &i));
    }
}

char    **expanded_args(char *str)
{
    char    **args;
    char    **globbing;
    size_t  i;

    str = cmd_pre_expand(str);
}