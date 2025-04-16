/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:54:47 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/16 10:13:48 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool    join_args(t_list **args)
{
    char *to_free;

    if(data.parse_error.type)
        return (false);
    if(!*args)
        *args = ft_strdup("");
    if(!*args)
        return (false);
    while(data.curr_token && data.curr_token->type == T_IDENTIFIER)
    {
        to_free = *args;
        *args = strjoin_args(*args, data.curr_token->value , ' ');
        if(!*args)
            return (free(to_free) , false);
        free(to_free);
        next_token();
    }
    return (true);
}

t_node    *parse_single_cmd(void)
{
    t_node  *node;
    
    if(data.parse_error.type)
        return (NULL);
    node = lstnew(N_CMD);
    if(!node)
        return (set_error(E_MEM) , NULL);
    while(data.curr_token && (data.curr_token->type == T_IDENTIFIER || redirection(data.curr_token->type)))
    {
        if(data.curr_token->type == T_IDENTIFIER)
        {
            if(!join_args(&(node->args)))
                
        }
    }
    return (node);
}