/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:20 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/11 20:32:30 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	export_list(void)
{
	t_env	*env;

	env = g_data.envlst;
	while (env)
	{
		if (ft_strcmp(env->key, "_") != 0)
		{
			printf("declare -x %s", env->key);
			if (env->value)
			{
				printf("=\"");
				for (size_t i = 0; env->value[i]; i++)
				{
					if (env->value[i] == '$' || env->value[i] == '"')
						printf("\\%c", env->value[i]);
					else
						printf("%c", env->value[i]);
				}
				printf("\"");
			}
			printf("\n");
		}
		env = env->next;
	}
}

int	ft_export(char **args)
{
	int		i;
	int		status;
	char	*key;
	char	*val;
	char	*joined;
	t_env	*existing;
	bool	append;

	i = 1;
	status = 0;
	if (!args[1])
		return (export_list(), 0);
	while (args[i])
	{
		if (!args[i][0])
		{
			i++;
			continue ;
		}
		if (!is_valid_identifier(args[i]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			status = 1;
			i++;
			continue ;
		}
		append = ft_strnstr(args[i], "+=", ft_strlen(args[i])) != NULL;
		key = extract_key_export(args[i]);
		val = extract_value_export(args[i]);
		existing = get_env(key);
		if (append)
		{
			if (existing && existing->value)
			{
				joined = ft_strjoin(existing->value, val ? val : "");
				update_envlst_export(key, joined, false);
				free(joined);
			}
			else
			{
				update_envlst_export(key, val ? val : "", true);
			}
		}
		else
		{
			update_envlst_export(key, val, existing ? false : true);
		}
		free(key);
		if (val)
			free(val);
		i++;
	}
	return (status);
}
