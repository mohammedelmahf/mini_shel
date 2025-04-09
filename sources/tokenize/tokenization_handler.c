/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:31:19 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/09 09:34:00 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
        if(!ft_strncmp)
    }
}