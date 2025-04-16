/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:05:54 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/15 11:21:18 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

#define PROMPT "minishell> "

typedef	enum	s_token_type
{
	T_IDENTIFIER,   // Command name or argument
	T_LESS,         // <
	T_GREAT,        // >
	T_DLESS,        // <<
	T_DGREAT,       // >>
	T_PIPE,         // |
	T_O_PARENT,     // (
	T_C_PARENT,     // )
	T_AND,          // &&
	T_OR,           // ||
	T_NL            // End of line (or newline)
}				t_token_type;

typedef struct	s_token
{
	t_token_type			type;
	char				*value;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

t_token		*tokenize(void);
t_token 	*new_token(char *value , t_token_type type);
t_token 	*tokenization_handler(char *line);
int 		handle_separator(char **line , t_token **token_list);
int 		append_separator(t_token_type type , char **line , t_token **token_list);
void 		token_list_add_back(t_token **list , t_token *new_token);
void 		print_delimiter_error(char c);
int 		ft_is_separator(char *str);
bool 		skip_delimiter(char *line , size_t *i);
int 		check_is_string_delimiter(char c);
void 		token_list_add_back(t_token **list , t_token *new_token);
t_token 	*new_token(char *value , t_token_type type);
int 		append_identifier(char **line , t_token **token_list);
void 		free_token_list(t_token **token_list);
void 		skipe_spaces(char **line);
#endif

