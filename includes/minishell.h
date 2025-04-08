/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:04:20 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/08 19:36:59 by maelmahf         ###   ########.fr       */
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
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "tokenizing.h"
#include <limits.h>
#include "parsing.h"


// # define STDIN 0
// # define STDOUT 1
// # define STDERR 2

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
	t_node			*ast;
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
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memset(void *s, int c, size_t n);
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
int	ft_strncmp(const char *s1, const char *s2, size_t n);
//env
char    *extract_value(char *str);
char    *extract_value(char *str);
void    init_envlst(void);
void    envlst_back(t_env *new);
void    update_envlst(char *key,char *value, bool create);
//exec
void    *garbage_collector(char *str , bool clean);
//signal
void    init_signal(void);
// ft_pwd.c
int  ft_pwd (void);
//ft_cd.c
int ft_cd(char **arg);
//cd_utils
char *ft_getenv(char *key);
//cleaning
void    clean_all(void);
#endif