/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:48:42 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/14 09:54:23 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool    curr_token_type_is_binop(void)
{
    t_token_type  *type;

    if(!data.curr_token)
        return (false);
    type = data.curr_token->type;
    if(type == T_AND || type == T_OR || type == T_PIPE)
        return (true);
    return (false);
}