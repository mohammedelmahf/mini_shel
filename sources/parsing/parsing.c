/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:52:12 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/13 18:48:19 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*terms(void)
{
	t_node	*node;

	if (g_data.parse_error.type)
		return (NULL);
	if (curr_token_type_is_binop() || g_data.curr_token->type == T_C_PARENT)
		return (set_error(E_SYNTAX), NULL);
	else if (g_data.curr_token->type == T_O_PARENT)
	{
		next_token();
		node = parsing_ast(0);
		if (!node)
			return (set_error(E_MEM), NULL);
		if (!g_data.curr_token || g_data.curr_token->type != T_C_PARENT)
		{
			clear_ast(&node);
			return (set_error(E_SYNTAX), NULL);
		}
		next_token();
		return (node);
	}
	else
		return (parse_single_cmd());
}

static bool	is_binop_with_prec(int min_prec)
{
	return (curr_token_type_is_binop() && curr_token_prec() >= min_prec);
}

static t_node	*parse_right_node(int n_prec)
{
	t_node	*right;

	if (!g_data.curr_token)
		return (set_error(E_SYNTAX), NULL);
	right = parsing_ast(n_prec);
	return (right);
}

t_node	*parsing_ast(int minimum_precedence)
{
	t_node			*left;
	t_node			*right;
	t_token_type	type;
	int				n_prec;

	if (g_data.parse_error.type || !g_data.curr_token)
		return (NULL);
	left = terms();
	if (!left)
		return (NULL);
	while (is_binop_with_prec(minimum_precedence))
	{
		type = g_data.curr_token->type;
		next_token();
		n_prec = prec(type) + 1;
		right = parse_right_node(n_prec);
		if (!right)
			return (left);
		left = join_nodes(type, left, right);
		if (!left)
			return (clear_ast(&left), clear_ast(&right), NULL);
	}
	return (left);
}
