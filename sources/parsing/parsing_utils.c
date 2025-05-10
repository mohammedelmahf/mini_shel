/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:48:42 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/10 12:18:11 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool curr_token_type_is_binop(void)
{
    t_token_type type;

    if (!g_data.curr_token)
        return (false);
    type = g_data.curr_token->type;
    if (type == T_AND || type == T_OR || type == T_PIPE)
        return (true);
    return (false);
}

void    next_token(void)
{
    g_data.curr_token = g_data.curr_token->next;
}

int    curr_token_prec(void)
{
    return (prec(g_data.curr_token->type));
}

int     prec(t_token_type type)
{
    if(type == T_AND || type == T_OR)
        return (0);
    return (1);
}

bool	redirection(t_token_type type)
{
	if (type == T_LESS || type == T_GREAT
		|| type == T_DLESS || type == T_DGREAT)
		return (true);
	return (false);
}