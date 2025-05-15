/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:30:32 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/15 16:56:51 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_split(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	*build_cmd_path(char *dir, char *cmd)
{
	char	*tmp1;
	char	*tmp2;
	char	*joined;

	tmp1 = ft_strdup(dir);
	tmp2 = ft_strdup(cmd);
	joined = ft_strjoin_args(tmp1, tmp2, '/');
	free(tmp1);
	free(tmp2);
	return (garbage_collector(joined, false));
}

static t_path	find_cmd_in_path(char **split_path, char *cmd)
{
	t_err	err;
	size_t	i;
	char	*cmd_path;

	i = 0;
	while (split_path[i])
	{
		cmd_path = build_cmd_path(split_path[i], cmd);
		err = check_exec(cmd_path, true);
		if (err.num == ENO_SUCCESS)
			return ((t_path){err, cmd_path});
		i++;
	}
	return ((t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL});
}

t_path	get_env_path(char *path, char *cmd)
{
	t_path	result;
	char	**split_path;

	split_path = ft_split(path, ':');
	result = find_cmd_in_path(split_path, cmd);
	free_split(split_path);
	return (result);
}

t_path	get_path(char *cmd)
{
	t_err	err;
	t_env	*env;
	char	*value;

	if (!cmd || !cmd[0])
		return ((t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd},
			NULL});
	if (ft_strchr(cmd, '/'))
	{
		err = check_exec(cmd, false);
		return ((t_path){err, gc_strdup(cmd)});
	}
	env = get_env("PATH");
	value = NULL;
	if (env)
		value = env->value;
	if (!value || !*value)
		return ((t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd},
			NULL});
	return (get_env_path(value, cmd));
}
