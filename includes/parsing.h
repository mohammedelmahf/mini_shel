/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:39:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/14 14:29:50 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

typedef struct s_node
{
	t_node_type			type;
	//t_io_node			*io_list;
	char				*args;
	char				**expanded_args;
	struct s_node		*left;
	struct s_node		*right;
}	t_node;

typedef enum e_parse_err_type
{
    E_MEM = 1,
    E_SYNTAX

}            t_parse_err_type;

typedef enum e_node_type
{
	N_PIPE,
	N_AND,
	N_OR,
	N_CMD
}	t_node_type;

typedef struct s_parse_err
{
    t_parse_err_type   type;
    char                *str;

}              t_parse_err;
t_node  *start_parsing(void);
void    set_error(t_parse_err_type type);
bool    curr_token_type_is_binop(void);

#endif