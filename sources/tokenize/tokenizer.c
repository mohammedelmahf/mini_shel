/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:48:32 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/05 11:20:59 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token *tokenize(void)
{
    char *line;
    t_token *token_list;

    line = data.line;
    token_list = tokenization_handler(line);
    free(line);
    data.line = NULL;
    return (token_list);
}