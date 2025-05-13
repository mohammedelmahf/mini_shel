/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:45:29 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/13 18:45:58 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*join_nodes(t_token_type type, t_node *left, t_node *right)
{
	t_node	*node;

	if (g_data.parse_error.type)
		return (NULL);
	node = lstnew(get_node_type(type));
	if (!node)
		return (set_error(E_MEM), NULL);
	node->left = left;
	node->right = right;
	return (node);
}

t_node	*start_parsing(void)
{
	t_node	*ast;

	g_data.curr_token = g_data.tokens;
	ast = parsing_ast(0);
	if (g_data.curr_token)
		return (set_error(E_SYNTAX), NULL);
	return (ast);
}
