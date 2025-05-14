/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:30:32 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/13 10:32:01 by maelmahf         ###   ########.fr       */
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

t_path	get_env_path(char *path, char *cmd)
{
	size_t	i;
	t_err	err;
	char	*cmd_path;
	char	**split_path;
	char	*tmp1;
	char	*tmp2;
	char	*joined;

	i = 0;
	split_path = ft_split(path, ':');
	while (split_path[i])
	{
		tmp1 = ft_strdup(split_path[i]);
		tmp2 = ft_strdup(cmd);
		joined = ft_strjoin_args(tmp1, tmp2, '/');
		cmd_path = garbage_collector(joined, false);
		free(tmp1);
		free(tmp2);
		err = check_exec(cmd_path, true);
		if (err.num == ENO_SUCCESS)
		{
			free_split(split_path);
			return ((t_path){(t_err){ENO_SUCCESS, ERRMSG_NONE, NULL},
				cmd_path});
		}
		i++;
	}
	free_split(split_path);
	return ((t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL});
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
		return ((t_path){err, ft_strdup(cmd)});
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
