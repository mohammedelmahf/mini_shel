/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:52:12 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/11 10:45:14 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node  *parsing_ast(int minimum_precedence)
{
    
}

t_node  *start_parsing()
{
    t_node  *ast;
    
    data.curr_token = data.tokens;
    ast = parsing_ast(0);
}