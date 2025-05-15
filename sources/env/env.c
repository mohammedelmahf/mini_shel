/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:28:33 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/15 08:57:56 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*extract_key(char *str)
{
	size_t	i;
	char	*key;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			key = ft_substr(str, 0, i);
			if (!key)
				return (NULL);
			return (garbage_collector(key, false));
		}
		i++;
	}
	key = ft_strdup(str);
	if (!key)
		return (NULL);
	return (garbage_collector(key, false));
}

char	*extract_value(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (garbage_collector(ft_substr(str, i, ft_strlen(str) - i),
					false));
		}
		i++;
	}
	return (NULL);
}

static void	set_default_env(void)
{
	char	cwd[PATH_MAX];

	if (!get_env("OLDPWD"))
		update_envlst(ft_strdup("OLDPWD"), NULL, true);
	if (!get_env("PWD"))
	{
		if (getcwd(cwd, sizeof(cwd)))
			update_envlst(ft_strdup("PWD"), ft_strdup(cwd), true);
		else
			update_envlst(ft_strdup("PWD"), ft_strdup("/"), true);
	}
	if (!get_env("SHLVL"))
		update_envlst(ft_strdup("SHLVL"), ft_strdup("1"), true);
	if (!get_env("PATH"))
		update_envlst(ft_strdup("PATH"),
			ft_strdup("/usr/local/sbin:/usr/local/bin:"
				"/usr/sbin:/usr/bin:/sbin:/bin"),
			true);
	update_envlst(ft_strdup("_"), ft_strdup("./minishell"), true);
}

void	init_envlst(void)
{
	int		i;
	char	**environ;
	char	*key;
	char	*value;

	i = 0;
	g_data.envlst = NULL;
	environ = g_data.environ;
	if (environ)
	{
		while (environ[i])
		{
			key = extract_key(environ[i]);
			value = extract_value(environ[i]);
			update_envlst(key, value, true);
			i++;
		}
	}
	set_default_env();
}
