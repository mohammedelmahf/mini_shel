/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:52:12 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/10 10:27:14 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node  *terms(void)
{
    t_node *node;

    if(data.parse_error.type)
        return (NULL);
    if(curr_token_type_is_binop() || data.curr_token->type == T_C_PARENT)
        return (set_error(E_SYNTAX) , NULL);
    else if(data.curr_token->type == T_O_PARENT)
    {
        next_token();
        node = parsing_ast(0);
        if(!node)
            return (set_error(E_MEM) , NULL);
        if(!data.curr_token|| data.curr_token->type != T_C_PARENT)
            return (set_error(E_SYNTAX) , node);
        next_token();
        return (node);
    }
    else
        return (parse_single_cmd());
}


t_node  *parsing_ast(int minimum_precedence)
{
    t_node  *left;
    t_node  *right;
    t_token_type    type;
    int n_prec ;
    
    if(data.parse_error.type || !data.curr_token)
        return (NULL);
    left = terms();
    if(!left)
        return (NULL);
    while(curr_token_type_is_binop() && curr_token_prec() >= minimum_precedence)
    {
        type = data.curr_token->type;
        next_token();
        if(!data.curr_token)
            return (set_error(E_SYNTAX) , left);
        n_prec = prec(type) + 1;
        right = parsing_ast(n_prec);
        if(!right)
            return(left);
        left = join_nodes(type , left , right);
        if (!left)
           return (clear_ast(&left) , clear_ast(&right) , NULL);
    }
    return (left);
}

t_node      *join_nodes(t_token_type type , t_node *left , t_node *right)
{
    t_node *node;

    if(data.parse_error.type)
        return (NULL);
    node = lstnew(get_node_type(type));
    if(!node)
        return(set_error(E_MEM) , NULL);
    node->left = left;
    node->right = right;
    return (node);
}

t_node  *start_parsing(void)
{
    t_node  *ast;
    
    data.curr_token = data.tokens;
    ast = parsing_ast(0);
    if(data.curr_token)
        return (set_error(E_SYNTAX) , NULL);
    return (ast);
}