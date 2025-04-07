/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:27:00 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 19:20:33 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    update_envlst(char *key,char *value, bool create)
{
    t_env   *envlst;

    envlst = data.envlst;
    while(envlst)
    {
        if(!ft_strcmp(key ,envlst->key))
        {
            if(value)
                envlst = garbage_collector(ft_strdup(value) , false);
            return ;
        }
        envlst = envlst->next;
    }
    if(create)
}