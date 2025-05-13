/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:20 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/13 12:26:06 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	export_err_msg(char *identifier)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(identifier, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

static	void	export_list(void)
{
	t_env	*list;
	size_t	i;

	list = g_data.envlst;
	while (list)
	{
		if (list->value != NULL && (ft_strcmp(list->key, "_") != 0))
		{
			printf("declare -x %s=\"", list->key);
			i = 0;
			while ((list->value)[i])
			{
				if ((list->value)[i] == '$' || (list->value)[i] == '"')
					printf("\\%c", (list->value)[i++]);
				else
					printf("%c", (list->value)[i++]);
			}
			printf("\"\n");
		}
		else if (list->value == NULL && (ft_strcmp(list->key, "_") != 0))
			printf("declare -x %s\n", list->key);
		list = list->next;
	}
}

int	check_key(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(*str) && *str != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	ft_export(char **argv)
{
	int		i;
	int		exit_s;
	char	*key;

	exit_s = 0;
	i = 1;
	if (!argv[1])
		return (export_list(), 0);
	while (argv[i])
	{
		if (check_key(argv[i]) == 0)
			exit_s = export_err_msg(argv[i]);
		else
		{
			key = extract_key(argv[i]);
			if (env_entry_exists(key))
				update_envlst(key, extract_value(argv[i]), false);
			else
				update_envlst(key, extract_value(argv[i]), true);
		}
		i++;
	}
	return (exit_s);
}


bool	env_entry_exists(char *key)
{
	t_env	*envlst;

	envlst = g_data.envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
			return (true);
		envlst = envlst->next;
	}
	return (false);
}

// void	export_list(void)
// {
// 	t_env	*env;

// 	env = g_data.envlst;
// 	while (env)
// 	{
// 		if (ft_strcmp(env->key, "_") != 0)
// 		{
// 			printf("declare -x %s", env->key);
// 			if (env->value)
// 			{
// 				printf("=\"");
// 				for (size_t i = 0; env->value[i]; i++)
// 				{
// 					if (env->value[i] == '$' || env->value[i] == '"')
// 						printf("\\%c", env->value[i]);
// 					else
// 						printf("%c", env->value[i]);
// 				}
// 				printf("\"");
// 			}
// 			printf("\n");
// 		}
// 		env = env->next;
// 	}
// }

// int	ft_export(char **args)
// {
// 	int		i;
// 	int		status;
// 	char	*key;
// 	char	*val;
// 	char	*joined;
// 	t_env	*existing;
// 	bool	append;

// 	i = 1;
// 	status = 0;
// 	if (!args[1])
// 		return (export_list(), 0);
// 	while (args[i])
// 	{
// 		if (!args[i][0])
// 		{
// 			i++;
// 			continue ;
// 		}
// 		if (!is_valid_identifier(args[i]))
// 		{
// 			ft_putstr_fd("minishell: export: `", 2);
// 			ft_putstr_fd(args[i], 2);
// 			ft_putstr_fd("': not a valid identifier\n", 2);
// 			status = 1;
// 			i++;
// 			continue ;
// 		}
// 		append = ft_strnstr(args[i], "+=", ft_strlen(args[i])) != NULL;
// 		key = extract_key_export(args[i]);
// 		val = extract_value_export(args[i]);
// 		existing = get_env(key);
// 		if (append)
// 		{
// 			if (existing && existing->value)
// 			{
// 				joined = ft_strjoin(existing->value, val ? val : "");
// 				update_envlst_export(key, joined, false);
// 				free(joined);
// 			}
// 			else
// 			{
// 				update_envlst_export(key, val ? val : "", true);
// 			}
// 		}
// 		else
// 		{
// 			update_envlst_export(key, val, existing ? false : true);
// 		}
// 		free(key);
// 		if (val)
// 			free(val);
// 		i++;
// 	}
// 	return (status);
// }
