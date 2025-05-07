/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:13:27 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/07 09:36:48 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token     *new_token(char *value , t_token_type type)
{
    t_token *new_token;

    new_token = (t_token *)ft_calloc(1 , sizeof(t_token));
    if(!new_token)
        return (NULL);
    new_token->value = value;
    new_token->type = type;
    return (new_token);
}

void    token_list_add_back(t_token **list , t_token *new_token)
{
    t_token *curr_node;

    if(!*list)
    {
        *list = new_token;
        return ;
    }
    curr_node = *list;
    while(curr_node && curr_node->next)
        curr_node = curr_node->next;
    curr_node->next = new_token;
    new_token->prev = curr_node;
}


void    free_token_list(t_token **token_list)
{
    t_token *curr_node;
    t_token *next_node;

    curr_node = *token_list;
    if(!curr_node)
        return ;
    while(curr_node)
    {
        free(curr_node->value);
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    *token_list = NULL;
}