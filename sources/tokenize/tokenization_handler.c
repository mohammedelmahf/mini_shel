/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:31:19 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/09 09:54:18 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int         handle_separator(char **line , char **token_list)
{
    if (!ft_strncmp(*line , ">>" , 2))
        return(append_separator(T_DGREAT , line , token_list));
    else if (!ft_strncmp(*line , "<<" , 2))
        return(append_separator(T_DLESS , line , token_list));
    else if (!ft_strncmp(*line , "<" , 1))
        return(append_separator( T_LESS , line , token_list));
    else if (!ft_strncmp(*line , ">" , 1))
        return(append_separator(T_GREAT , line , token_list));
    else if (!ft_strncmp(*line , "||" , 2))
        return(append_separator( T_OR, line , token_list));
    else if (!ft_strncmp(*line , "&&" , 2))
        return(append_separator( T_AND, line , token_list));
    else if (!ft_strncmp(*line , "(" , 1))
        return(append_separator( T_O_PARENT, line , token_list));
    else if (!ft_strncmp(*line , ")" , 1))
        return(append_separator(T_C_PARENT , line , token_list));
    else
        return(append_separator(T_PIPE , line , token_list));
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
            return(clear_token_list(&token_list) , NULL);
        if(!ft_strncmp(line , "<" , 1) || !ft_strncmp(line , ">" , 1)
            || !ft_strncmp(line , "|" , 1) || !ft_strncmp(line , "&&" , 2)
            || !ft_strncmp(line , "(" , 1) || !ft_strncmp(line , ")" , 1) )
            error = (!handle_separator(&line , &token_list) && 1); 
    }
}