/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:48:32 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/10 12:15:50 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token *tokenize(void)
{
    char *line;
    t_token *token_list;

    line = g_data.line;
    token_list = tokenization_handler(line);
    free(line);
    g_data.line = NULL;
    return (token_list);
}