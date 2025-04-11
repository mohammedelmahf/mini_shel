/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:39:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/11 11:08:50 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

typedef struct s_node
{
	//t_node_type			type;
	//t_io_node			*io_list;
	char				*args;
	char				**expanded_args;
	struct s_node		*left;
	struct s_node		*right;
}	t_node;

typedef struct s_parse_err
{
    t_pars_error_type   type;
    char                *str;
    
}              t_pars_error;

typedef enum s_pars_error_type
{
    E_MEM = 1,
    E_SYNTAX
    
}            t_pars_error_type;
t_node  *start_parsing(void);

#endif