/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:52:12 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/14 09:57:41 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node  *terms()
{
    t_node *node;

    if(data.parse_error.type)
        return (NULL);
    if(curr_token_type_is_binop() || data.curr_token->type = T_C_PARENT)
        return (set_error(E_SYNTAX) , NULL);
}
t_node  *parsing_ast(int minimum_precedence)
{
    t_node  *left;
    t_node  *right;
    
    if(data.parse_error.type || !data.curr_token)
        return (NULL);
    left = terms();
}

t_node  *start_parsing(void)
{
    t_node  *ast;
    
    data.curr_token = data.tokens;
    ast = parsing_ast(0); //expression
}