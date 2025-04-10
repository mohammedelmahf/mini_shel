/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:18:49 by iel-asef          #+#    #+#             */
/*   Updated: 2025/04/09 19:18:57 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H


//pwd.c
int  ft_pwd (void);
//cd.c
int ft_cd(char **arg);
//utils
char	*ft_getenv(const char *name);

//exit

//export 
int parsinge_export(char *str);

//echo 
int	ft_echo(char **str);
int  parsinge_echo(char *str);
#endif