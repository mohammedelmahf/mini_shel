/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:31:19 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/15 22:15:19 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int         handle_separator(char **line , t_token **token_list)
{
    if (!ft_strncmp(*line , ">>" , 2))
        return(append_separator(T_DGREAT , line , token_list) && 1);
    else if (!ft_strncmp(*line , "<<" , 2))
        return(append_separator(T_DLESS , line , token_list) && 1);
    else if (!ft_strncmp(*line , "<" , 1))
        return(append_separator( T_LESS , line , token_list) && 1);
    else if (!ft_strncmp(*line , ">" , 1))
        return(append_separator(T_GREAT , line , token_list) && 1);
    else if (!ft_strncmp(*line , "||" , 2))
        return(append_separator( T_OR, line , token_list) && 1);
    else if (!ft_strncmp(*line , "&&" , 2))
        return(append_separator( T_AND, line , token_list) && 1);
    else if (!ft_strncmp(*line , "(" , 1))
        return(append_separator( T_O_PARENT, line , token_list) && 1);
    else if (!ft_strncmp(*line , ")" , 1))
        return(append_separator(T_C_PARENT , line , token_list) && 1);
    else
        return(append_separator(T_PIPE , line , token_list) & 1);
}

t_token    *tokenization_handler(char *line)
{
    int     error;
    t_token *token_list;

    error = 0;
    token_list = NULL;
    while(*line)
    {
        if(error)
            return(free_token_list(&token_list) , NULL);
        if(ft_isspace(*line))
            skipe_spaces(&line);
        if(!ft_strncmp(line , "<" , 1) || !ft_strncmp(line , ">" , 1)
            || !ft_strncmp(line , "|" , 1) || !ft_strncmp(line , "&&" , 2)
            || !ft_strncmp(line , "(" , 1) || !ft_strncmp(line , ")" , 1) )
            error = (!handle_separator(&line , &token_list) && 1);
        else
            error = (!append_identifier(&line , &token_list) && 1);
    }
    return (token_list);
}