/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_appenders.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:48:55 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/10 12:38:26 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int append_separator(t_token_type type , char **line , t_token **token_list)
{
    t_token *token;

    token = new_token(NULL , type);
    if(!token)
        return (0);
    token_list_add_back(token_list , token);
    (*line)++;
    if(type == T_DGREAT || type == T_DLESS || type == T_AND || type == T_OR )
        (*line)++;
    return (1);
}

int append_identifier(char **line , t_token **token_list)
{
    char *line_tmp;
    char *value;
    t_token *token;
    size_t i;

    i = 0;
    line_tmp = *line;
    
    while(line_tmp[i] && !ft_is_separator(line_tmp + i))
    {
        if(check_is_string_delimiter(line_tmp[i]))
        {
            if(!skip_delimiter(line_tmp , &i))
                return (print_delimiter_error(line_tmp[i]) , 0);
        }
        else
            i++;
    }
    value = ft_substr(line_tmp , 0 ,i);
    if(!value)
        return (0);
    token = new_token(value , T_IDENTIFIER);
    if(!token)
        return (free(value) , 0);
    *line += i;
    return(token_list_add_back(token_list , token) , 1);
    
}