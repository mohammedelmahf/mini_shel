/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:03:43 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 11:30:20 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool init_env(t_data *data , char **env)
{
    int i;

    data->env = ft_calloc(env_var_count(env) + 1 , sizeof * data->env);
    if(!data->env)
        return (false);
    i = 0;
    while (env[i])
    {
        data->env[i] = ft_strdup(env[i]);
        if(!data->env[i])
            return (false);
        i++;
    }
    return (true);
    
}

static bool init_wdr(t_data *data)
{
    
}

bool    init_data(t_data *data , char **env)
{
    if(!init_env(data, env))
    {
        error_msg_cmd("Fatal", NULL, "Could not initialize environment", 1);
        return (false);
    }
    if(!init_wdr(data))
    {
        error_msg_cmd("Fatal", NULL, "Could not initialize working directories", 1);
        return (false);
    }
    data->token = NULL;
    data->user_input = NULL;
    data->cmd = NULL;
    data->pid = -1;
    
}