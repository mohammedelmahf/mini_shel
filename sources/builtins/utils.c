/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:28 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/10 17:28:55 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*envlst_new_old(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = garbage_collector(ft_strdup(key), false);
	if (value)
		new->value = garbage_collector(ft_strdup(value), false);
	new->next = NULL;
	return (new);
}

void	update_oldpwd(char *key, char *value, bool create)
{
	t_env	*envlst;

	envlst = g_data.envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
		{
			if (value)
			{
				envlst->value = garbage_collector(ft_strdup(value), false);
			}
			return ;
		}
		envlst = envlst->next;
	}
	if (create)
		envlst_back(envlst_new_old(key, value));
}

t_env	*get_env(char *key)
{
	t_env	*tmp;

	tmp = g_data.envlst;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
