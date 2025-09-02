/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:54:47 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/26 09:34:15 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	append_io_node(t_io_node **lst, t_io_node *new)
{
	t_io_node	*curr_node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr_node = *lst;
	while (curr_node && curr_node->next)
		curr_node = curr_node->next;
	curr_node->next = new;
}

bool	get_io_list(t_io_node **io_list)
{
	t_token_type	redir_type;
	t_io_node		*tmp_io_node;

	if (g_data.parse_error.type)
		return (false);
	while (g_data.curr_token && redirection(g_data.curr_token->type))
	{
		redir_type = g_data.curr_token->type;
		next_token();
		if (!g_data.curr_token)
			return (set_error(E_SYNTAX), false);
		if (g_data.curr_token->type != T_IDENTIFIER)
			return (set_error(E_SYNTAX), false);
		tmp_io_node = new_io_node(redir_type, g_data.curr_token->value);
		if (!tmp_io_node)
			return (set_error(E_MEM), false);
		append_io_node(io_list, tmp_io_node);
		next_token();
	}
	return (true);
}

bool	join_args(char **args)
{
	if (g_data.parse_error.type)
		return (false);
	if (!*args)
		*args = gc_strdup("");
	if (!*args)
		return (false);
	while (g_data.curr_token && g_data.curr_token->type == T_IDENTIFIER)
	{
		*args = ft_strjoin_args(*args, g_data.curr_token->value, ' ');
		if (!*args)
			return (false);
		next_token();
	}
	return (true);
}

t_node	*parse_single_cmd(void)
{
	t_node	*node;

	if (g_data.parse_error.type)
		return (NULL);
	node = lstnew(N_CMD);
	if (!node)
		return (set_error(E_MEM), NULL);
	while (g_data.curr_token && (g_data.curr_token->type == T_IDENTIFIER
			|| redirection(g_data.curr_token->type)))
	{
		if (g_data.curr_token->type == T_IDENTIFIER)
		{
			if (!join_args(&(node->args)))
				return (clear_cmd_node(node), set_error(E_MEM), NULL);
		}
		else if (redirection(g_data.curr_token->type))
		{
			if (!get_io_list(&(node->io_list)))
				return (free(node->args), free(node), NULL);
		}
	}
	return (node);
}
