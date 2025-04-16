/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:54:47 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/16 14:11:07 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	get_io_list(t_io_node **io_list)
{
	t_token_type		redir_type;
	t_io_node			*tmp_io_node;

	if (data.parse_error.type)
		return (false);
	while (data.curr_token && redirection(data.curr_token->type))
	{
		redir_type = data.curr_token->type;
		next_token();
		if (!data.curr_token)
			return (set_error(E_SYNTAX), false);
		if (data.curr_token->type != T_IDENTIFIER)
			return (set_error(E_SYNTAX), false);
		tmp_io_node = new_io_node(redir_type, data.curr_token->value); 
		if (!tmp_io_node)
			return (set_error(E_MEM), false);
		//append_io_node(io_list, tmp_io_node);
		next_token();
	}
	return (true);
}

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
                return(clear_cmd_node(node) , set_error(E_MEM), NULL);
        }
        else if (redirection(data.curr_token->type))
        {
            if(!get_io_list(&(node->io_list)))
                return(free(node->args) , free(node), NULL);
        }
    }
    return (node);
}