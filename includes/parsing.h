/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:39:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/10 12:24:33 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include "tokenizing.h"
typedef enum e_parse_err_type
{
	E_MEM = 1,
	E_SYNTAX

}						t_parse_err_type;

typedef enum e_node_type
{
	N_PIPE,
	N_AND,
	N_OR,
	N_CMD
}						t_node_type;

typedef enum e_io_type
{
	IO_IN,
	IO_OUT,
	IO_APPEND,
	IO_HEREDOC
}						t_io_type;

typedef struct s_io_node
{
	t_io_type			type;
	char				*value;
	char				**expanded_value;
	int					here_doc;
	struct s_io_node	*prev;
	struct s_io_node	*next;
}						t_io_node;

typedef struct s_node
{
	t_node_type			type;
	t_io_node			*io_list;
	char				*args;
	char				**expanded_args;
	struct s_node		*left;
	struct s_node		*right;
}						t_node;

typedef struct s_parse_err
{
	t_parse_err_type	type;
	char				*str;

}						t_parse_err;

t_node					*start_parsing(void);
void					set_error(t_parse_err_type type);
void					set_error(t_parse_err_type type);
bool					curr_token_type_is_binop(void);
t_node_type				get_node_type(t_token_type type);
t_node					*lstnew(t_node_type type);
void					next_token(void);
int						curr_token_prec(void);
int						prec(t_token_type type);
bool					redirection(t_token_type type);
t_node					*terms(void);
t_node					*parsing_ast(int minimum_precedence);
t_node					*join_nodes(t_token_type type, t_node *left,
							t_node *right);
void					clear_ast(t_node **ast);
bool					join_args(char **args);
t_node					*parse_single_cmd(void);
t_io_node				*new_io_node(t_token_type type, char *value);
void					append_io_node(t_io_node **lst, t_io_node *new);
void					clear_cmd_node(t_node *node);
void					clear_io_list(t_io_node **lst);
void					handle_parse_error(void);
#endif