/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:18:49 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/07 12:44:34 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H

struct s_env;
typedef struct s_env t_env;

#include "minishell.h"

//pwd.c
int     ft_pwd(void);
//cd.c
int     ft_cd(char **arg);
int     change_pwd(void);
int     cd_err_msg(char * msg);
int     cd_home(void);
//utils
char	*ft_getenv(const char *name);
t_env   *get_env(char *key);

//export 
int     parsing_key(char *str);
int     ft_export(char **str);
void    export_list(void);
//echo 
int     ft_echo(char **str);
int     parsinge_echo(char *str);

//env
char    *extract_key(char *str);
void    envlst_back(t_env *new);
int     ft_env(void);
char	*ft_getenv(const char *name);
//unset
int     parsing_key(char *str);
int     ft_unset(char **s);
void    *garbage_collector(char *str , bool clean);
void    msg_err(char *s);
//exit 
long	ft_atoi(const char *str);
int     ft_exit(char **s);
bool    ft_isnumber(char *s);
int     ft_isdigit(int c);



#endif
