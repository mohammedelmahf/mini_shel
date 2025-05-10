/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:29:37 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/10 12:16:36 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	clear_io_list(t_io_node **lst)
{
	t_io_node	*curr_node;
	t_io_node	*next;

	curr_node = *lst;
	if (!curr_node)
		return ;
	while (curr_node)
	{
		free(curr_node->value);
		free_char2(curr_node -> expanded_value);
		next = curr_node->next;
		free(curr_node);
		curr_node = next;
	}
	*lst = NULL;
}

void	clear_cmd_node(t_node *node)
{
	if (!node)
		return ;
	clear_io_list(&(node -> io_list));
	free(node -> args);
	free_char2(node -> expanded_args);
}

void    recursive_ast_clear(t_node *node)
{
    if(!node)
        return ;
    if(node->type == N_CMD)
        clear_cmd_node(node);
    else
    {
        if(node->left)
            recursive_ast_clear(node->left);
        if(node->right)
            recursive_ast_clear(node->right);
    }
    free(node);
}

void    clear_ast(t_node **ast)
{
    recursive_ast_clear(*ast);
    *ast = NULL;
    free_token_list(&g_data.tokens);
}