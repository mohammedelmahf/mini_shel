/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:04:20 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 11:05:36 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
typedef struct s_data
{
    bool    interactive;
    char    **env;
    
}       t_data;
//utilss
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);
//utils
bool    usage_message(bool return_valu);
int error_msg_cmd(char *cmd , char *detail , char *erro_message , int error_nb);
bool    init_data(t_data *data , char **env);
//env
int env_var_count(char **env);

#endif