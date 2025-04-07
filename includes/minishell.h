/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:04:20 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 19:52:43 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <termios.h>


# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct	s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_data
{
	char			*line;
	t_token			*tokens;
	t_token			*curr_token;
//	t_node			*ast;
	int				exit_s;
	bool			signint_child;
//	t_parse_err		parse_err;
	int				stdin;
	int				stdout;
	char			**environ;
	t_env			*envlst;
	bool			heredoc_sigint;
	struct termios	original_term;
}					t_data;

extern t_data	data;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//utils
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
//env
char    *extract_value(char *str);
char    *extract_value(char *str);
void    init_envlst(void);
void    envlst_back(t_env *new);
//exec
void    *garbage_collector(char *str , bool clean);

#endif