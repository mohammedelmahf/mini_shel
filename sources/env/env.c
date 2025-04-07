/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:28:33 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 15:40:14 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int init_env(t_data *data , char **arr_env)
{
    t_env   *env;
    t_env   *new;
    int     i;

    if (!(env = malloc(sizeof(t_env))))
        return (0);
    env->value = ft_strdup(arr_env[0]);
    
}