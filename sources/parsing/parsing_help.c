/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:54:47 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/14 14:30:22 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    parse_single_cmd(void)
{
    t_node  *node;
    
    if(data.parse_error.type)
        return (NULL);
    node = lstnew(N_CMD);
    if(!node)
        return (set_error(E_MEM));
    while(data.curr_token && (data.curr_token->type == T_IDENTIFIER || redirection(data.curr_token->type)))
    {
        
    }
}