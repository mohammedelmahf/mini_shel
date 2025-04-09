/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:13:27 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/09 11:36:48 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token     *new_token(char *value , t_token_type type)
{
    t_token *new_token;

    new_token = (t_token *)ft_calloc(1 , sizeof(t_token));
    if(!new_token)
        return (NULL);
    new_token->value = value;
    new_token->type = type;
    return (new_token);
}