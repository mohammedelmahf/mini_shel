/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:00:58 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/29 16:29:11 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char   *handle_dollar(char *str , size_t *i)
{
    size_t start;
    char *var;
    char *env_value;

    
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
        return(ft_strdup("$"));
    start = *i;
    while(is_valid_var_char(str[*i]))
        (*i)++;
    var = ft_substr(str , start , *i - start );
    env_value = get_envlst_value(var);
    if (!env_value)
        return (free(var), ft_strdup(""));
    return (free(var), ft_strdup(env_value));
    
}

char    *cmd_pre_expand(char *str)
{
    char *expanded;
    size_t i;

    expanded = ft_strdup(str);
    i = 0;

    while(str[i])
    {
        if(str[i]  == '\'')
            expanded = ft_strjoin_f(expanded , handle_squotes(str , &i));
        else if(str[i] == '"')
            expanded = ft_strjoin_f(expanded , handle_dquotes(str , &i));
        else if(str[i] == '$')
            expanded = ft_strjoin_f(expanded , handle_dollar(str , &i));
        else
            expanded = ft_strjoin_f(expanded , handle_normal_str(str , &i));
    }
    return (expanded);
}

char    **expand_args(char *str)
{
    char    **expander;
    char    **globbed;
    size_t  i;

    str = cmd_pre_expand(str);
    if(!str)
        return (NULL);
    str = remove_empty_quotes(str);
    if(!str)
        return (NULL);
    expander = expander_split(str);
    free(str);
    if(!expander)
        return (NULL);
    
}