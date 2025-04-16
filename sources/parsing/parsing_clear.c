/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:29:37 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/16 18:47:34 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"



void    recursive_ast_clear(t_node *node)
{
    if(!node)
        return ;
    // if(node->type == N_CMD)
    //     clear_cmd_node(node);
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
    free_token_list(&data.tokens);
}