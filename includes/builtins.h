/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:18:49 by iel-asef          #+#    #+#             */
/*   Updated: 2025/04/16 23:00:48 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef BUILTINS_H
// #define BUILTINS_H

// // #include "../includes/minishell.h"

// #include "minishell.h"

// //pwd.c
// int  ft_pwd (void);
// //cd.c
// int ft_cd(char **arg);
// //utils
// char	*ft_getenv(const char *name);

// //exit

// //export 
// int parsinge_export(char *str);
// int  ft_export(char **str);
// //echo 
// int	ft_echo(char **str);
// int  parsinge_echo(char *str);
// //env
// char    *extract_key(char *str);
// void    envlst_back(t_env *new);
// int	ft_env(void);
// char	*ft_getenv(const char *name);
// // //utils env
// // static  t_env   *envlst_new(char *key , char *value);
// // void    envlst_back(t_env *new);
// // void    update_envlst(char *key,char *value, bool create);

// #endif
#ifndef BUILTINS_H
#define BUILTINS_H

struct s_env;
typedef struct s_env t_env;

#include "minishell.h"

//pwd.c
int  ft_pwd(void);
//cd.c
int ft_cd(char **arg);
//utils
char	*ft_getenv(const char *name);

//export 

int parsing_key(char *str);
int  ft_export(char **str);

//echo 
int	ft_echo(char **str);
int  parsinge_echo(char *str);

//env
char    *extract_key(char *str);
void    envlst_back(t_env *new);
int	ft_env(void);
char	*ft_getenv(const char *name);
t_env *get_env(char *key);
//unset
int parsing_key(char *str);
int ft_unset(char **s);
void    *garbage_collector(char *str , bool clean);
#endif
