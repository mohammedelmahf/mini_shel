/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:18:49 by iel-asef          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/14 16:10:28 by iel-asef         ###   ########.fr       */
=======
/*   Updated: 2025/04/10 21:59:49 by maelmahf         ###   ########.fr       */
>>>>>>> 75ccb5216dc6c8487d97a18e511ea284a1a7e8c6
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
int parsinge_export(char *str);
int  ft_export(char **str);

//echo 
int	ft_echo(char **str);
int  parsinge_echo(char *str);

//env
char    *extract_key(char *str);
<<<<<<< HEAD
void    envlst_back(t_env *new);
int	ft_env(void);
char	*ft_getenv(const char *name);
t_env *get_env(char *key);
=======
//void    envlst_back(t_env *new);
//int	ft_env(void);
//utils env
////static  t_env   *envlst_new(char *key , char *value);
////void    envlst_back(t_env *new);
//evoid    update_envlst(char *key,char *value, bool create);
>>>>>>> 75ccb5216dc6c8487d97a18e511ea284a1a7e8c6


#endif
