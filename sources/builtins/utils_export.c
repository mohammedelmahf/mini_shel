/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:04:18 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/11 21:04:24 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_valid_identifier(const char *str)
{
	int	i;

	i = 0;
	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	while (str[i] && str[i] != '=' && !(str[i] == '+' && str[i + 1] == '='))
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	*extract_key_export(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=' && !(str[i] == '+' && str[i + 1] == '='))
		i++;
	return (ft_substr(str, 0, i));
}

char	*extract_value_export(char *str)
{
	char	*sep;

	sep = ft_strnstr(str, "+=", ft_strlen(str));
	if (sep)
		return (ft_strdup(sep + 2));
	sep = ft_strchr(str, '=');
	if (sep)
		return (ft_strdup(sep + 1));
	return (NULL);
}

void	update_envlst_export(char *key, char *value, bool create)
{
	t_env	*envlst;

	envlst = g_data.envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
		{
			if (value)
			{
				free(envlst->value);
				envlst->value = ft_strdup(value);
			}
			return ;
		}
		envlst = envlst->next;
	}
	if (create)
		envlst_back(envlst_new_old(key, value));
}
