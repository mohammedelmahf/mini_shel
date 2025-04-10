/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_appenders.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:48:55 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/10 09:37:30 by maelmahf         ###   ########.fr       */
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

// int append_identifier(t_token_type , char **line , t_token **token_list)
// {
    
// }