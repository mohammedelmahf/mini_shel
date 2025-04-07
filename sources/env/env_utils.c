/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:27:00 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 19:37:00 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static  t_env   *envlst_new(char *key , char *value)
{
    t_env *new;

    new = (t_env *)ft_calloc(1 , sizeof(t_env));
    if(!new)
        return NULL;
    new->key = garbage_collector(ft_strdup(key) , false);
    if(value)
        new->value = garbage_collector(ft_strdup(value) , false);
    new->next = NULL;
    return (new);
}

void    envlst_back(t_env *new)
{
    t_env *curr;

    if(!data.envlst)
    {
        data.envlst = new;
        return ;
    }
    curr = data.envlst;
    while (curr && curr->next)
        curr = curr->next;
    curr->next = new;
    
}

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
        envlst_back(envlst_new(key,value));
}