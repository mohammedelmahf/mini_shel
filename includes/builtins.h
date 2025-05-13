/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:40:27 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/13 14:55:30 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include <stdbool.h>

struct	s_env;
typedef struct s_env	t_env;

// pwd.c
int		ft_pwd(void);

// cd.c
int		ft_cd(char **arg);
int		change_pwd(void);
int		cd_err_msg(char *msg);
int		cd_home(void);

// utils
char	*ft_getenv(const char *name);
t_env	*get_env(char *key);
void	update_oldpwd(char *key, char *value, bool create);
t_env	*envlst_new_old(char *key, char *value);

// export
int		ft_export(char **str);
bool	env_entry_exists(char *key);
// void	export_list(void);

// echo
int		ft_echo(char **str);
int		parsinge_echo(char *str);

// env
char	*extract_key(char *str);
void	envlst_back(t_env *new);
int		ft_env(char **args);

// unset
int		parsing_key(char *str);
int		ft_unset(char **s);
void	msg_err(char *s);

// exit
long	ft_atoi(const char *str);
int		ft_exit(char **s);
bool	ft_isnumber(char *s);
int		ft_isdigit(int c);

// utils_export
void	update_envlst_export(char *key, char *value, bool create);
char	*extract_value_export(char *str);
char	*extract_key_export(char *str);
int		is_valid_identifier(const char *str);

#endif
