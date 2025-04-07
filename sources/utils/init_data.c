/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:03:43 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 10:12:42 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool init_env(t_data *data , char **env)
{
    int i;

    data->env = ft_calloc(env_var_count(env) + 1 , sizeof * data->env);
}
bool    init_data(t_data *data , char **env)
{
    
}