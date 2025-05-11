/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:30:32 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/10 21:22:10 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

 t_path get_env_path(char *path, char *cmd)
{
    size_t i = 0;
    t_err err;
    char *cmd_path;
    char **split_path = ft_split(path, ':');

    while (split_path[i])
    {
        cmd_path = garbage_collector(ft_strjoin_args(
            ft_strdup(split_path[i]), ft_strdup(cmd), '/'), false);
        err = check_exec(cmd_path, true);
        if (err.num == ENO_SUCCESS)
            return (t_path){(t_err){ENO_SUCCESS, ERRMSG_NONE, NULL}, cmd_path};
        i++;
    }
    return (t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL};
}

t_path get_path(char *cmd)
{
	t_err	err;
	t_env	*env;
	char	*value;

	if (!cmd || !cmd[0])
		return (t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL};

	if (ft_strchr(cmd, '/'))
	{
		err = check_exec(cmd, false);
		return (t_path){err, ft_strdup(cmd)};
	}

	env = get_env("PATH");
	value = NULL;
	if (env)
		value = env->value;

	if (!value || !*value)
		return (t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL};

	return get_env_path(value, cmd);
}