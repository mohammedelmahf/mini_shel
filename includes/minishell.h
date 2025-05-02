/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:04:20 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/01 20:06:43 by iel-asef         ###   ########.fr       */
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
 #include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "tokenizing.h"
#include <limits.h>
#include "parsing.h"
#include "builtins.h"
#include "parsing.h"

#include <sys/wait.h>

// # define STDIN 0
// # define STDOUT 1
// # define STDERR 2

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;
				
typedef enum e_msg_err
{
	ERRMSG_CMD_NOT_FOUND,
	ERRMSG_NO_SUCH_FILE,
	ERRMSG_PERM_DENIED,
	ERRMSG_AMBIGUOUS,
	ERRMSG_TOO_MANY_ARGS,
	ERRMSG_NONE = 42 ,
	ERRMSG_NUMERIC_REQUI	
}	t_msg_err;

typedef enum e_direction
{
	TD_LEFT,
	TD_RIGHT
}	t_direction;

typedef enum e_err_num
{
	ENO_SUCCESS, // 0
	ENO_GENERAL, // 1
	ENO_NOT_FOUND, // 2
	ENO_CANT_EXEC = 126,
	ENO_EXEC_255 = 255  //SDTERR
}	t_err_num;
				
typedef struct s_err
{
	t_err_num	num;
	t_msg_err	msg;
	char		*cause;
}	t_err;
				
typedef struct s_path
{
	t_err	err;
	char	*path;
}	t_path;

typedef struct s_data
{
	char			*line;
	t_token			*tokens;
	t_token			*curr_token;
	t_node			*ast;
	int				exit_s;
	bool			signint_child;
	t_parse_err		parse_error;
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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
int		ft_isspace(char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_args(char const *s1, char const *s2, char c);
int		count(char const *s, char c);
char	*copy(char *str, int start, int end);
char	**ft_split(char const *s, char c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin_f(char *s1, char *s2);
//env
char    *extract_value(char *str);
char    *extract_value(char *str);
void    init_envlst(void);
void    envlst_back(t_env *new);
void    update_envlst(char *key,char *value, bool create);
char    *get_envlst_value(char *key);
t_env   *get_env(char *key);
//exec
void    *garbage_collector(char *str , bool clean);
//exec--init
bool    is_valid_var_char(char c);
void    init_tree(t_node *node);
void    init_leaf(t_node *node);
//exec--redirection
int 	exec_in(t_io_node *io_list , int *status);
int 	exec_out(t_io_node *io_list , int *status);
int	 	exec_append(t_io_node *io_list , int *status);
//exixit--check
t_err 	check_exec(char *file, bool cmd);
t_err 	check_write(char *file);
t_err 	check_read(char *file);
//exec--pipe
void    exec_pipe_child(t_node* tree , int pipfd[2] ,t_direction derection);
int		get_exit_status(int status);
int 	exec_pipe(t_node * tree);
int	 	exec_node( t_node *node , bool piped);
//exec--builtin
int 	exec_builtins(char **args);
bool    is_builtin(char *arg);
//exec--error_msg
int		ft_err_msg(t_err err);
//exec--external_commnad
int check_redirections(t_node *node);
void	reset_std(bool pipd);
int  exec_simple_cmd(t_node *node, bool pipe);
//exec--get path
t_path get_path(char *cmd);
t_path get_env_path(char *path, char *cmd);
//expand
char	*remove_empty_quotes(char *str);
char   *handle_dollar(char *str , size_t *i);
char    *cmd_pre_expand(char *str);
char    *handle_squotes(char *str , size_t *i);
char    **expand_args(char *str);
char    *handle_dquotes_str(char *str , size_t *i);
char   *handle_dquotes(char *str , size_t *i);
char	*handle_normal_str(char *str, size_t *i);
void    skip_word(char *str , size_t *i);
char    **expander_split(char *str);
//signal
void    init_signal(void);
void    handler_sigquit(int num);
//cleaning
void    clean_all(void);
void execute_cmd(char **args, char **envp);
#endif