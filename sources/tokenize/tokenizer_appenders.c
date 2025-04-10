/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_appenders.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:48:55 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/10 11:23:04 by maelmahf         ###   ########.fr       */
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
    int i;

    line_tmp = *line;
    
    while(line_tmp[i] && !ft_is_separator(line_tmp + 1))
    {
        if(check_is_string_delimiter(line_tmp[i]))
        {
            if(!skip_deliniter(line_tmp , &i))
                return (1)
        }
        i++;
    }
}