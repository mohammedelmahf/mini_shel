/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:20 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/08 23:32:14 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int parsing_key(char *str)
{
	int i = 0;

	if (!str || (!ft_isalpha(str[i]) && str[i] != '_'))
		return 0;
	i++;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return 0;
		i++;
	}
	return 1;
}

void export_list(void)
{
	t_env *env;
	size_t i;

	env = data.envlst;
	while (env)
	{
		if (env->value && ft_strcmp(env->key, "_") != 0)
		{
			printf("declare -x %s=\"", env->key);
			i = 0;
			while (env->value[i])
			{
				if (env->value[i] == '$' || env->value[i] == '"')
					printf("\\%c", env->value[i]);
				else
					printf("%c", env->value[i]);
				i++;
			}
			printf("\"\n");
		}
		else if (ft_strcmp(env->key, "_") != 0)
			printf("declare -x %s\n", env->key);
		env = env->next;
	}
}

int ft_export(char **str)
{
	int i ;
	int exit_status = 0;
	char *key;
	t_env *existing;

	if (!str[1])
	{
		export_list();
		return 0;
	}
	i = 1;
	while (str[i])
	{
		if (!parsing_key(str[i]))
		{
			ft_putstr_fd("minishell: export:" , 2);
			ft_putstr_fd(str[i] , 2);
			ft_putstr_fd (": not a valid identifier\n", 2);
			exit_status = 1;
		}
		else
		{
			key = extract_key(str[i]);
			existing = get_env(key); 
			if (existing)
				update_envlst(key, extract_value(str[i]), false); // update
			else
				update_envlst(key, extract_value(str[i]), true);  // add
		}
		i++;
	}
	return exit_status;
}