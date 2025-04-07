/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:04:20 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 11:43:31 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


extern int	g_last_exit_code;

typedef struct s_token
{

}       t_token;

typedef struct s_command
{
	char				*command;
}	t_command;

typedef struct s_data
{
    bool        interactive;
    char        **env;
    t_token     *token;
    char        *user_input;
    char		**env;
	char		*working_dir;
	char		*old_working_dir;
    t_command   *cmd;
    t_pid       pid;
    
}       t_data;
//utilss
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);
//utils
bool    usage_message(bool return_valu);
int error_msg_cmd(char *cmd , char *detail , char *error_message , int error_nb);
bool    init_data(t_data *data , char **env);
void    free_ptr(void *ptr);

//env
int env_var_count(char **env);

#endif