/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:36:49 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/29 16:29:14 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    init_leaf(t_node *node)
{
    if(node->args)
        node->expanded_args = expand_args(node->args);
        
}

void    init_tree(t_node *node)
{
    if (!node)
        return ;
    if(node->type == N_PIPE 
        || node->type == N_AND
        || node->type == N_OR)
    {
        init_tree(node->left);
        if(!data.heredoc_sigint)
            init_tree(node->right);
    }
    else    
        init_leaf(node);
}

