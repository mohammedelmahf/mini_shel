#include "../../includes/minishell.h"

static t_path get_env_path(char *path, char *cmd)
{
    size_t i = 0;
    t_err err;
    char *cmd_path;
    char **split_path = ft_split(path, ':');

    while (split_path[i])
    {
        cmd_path = ft_garbage_collector(ft_strjoin_args(
            ft_strdup(split_path[i]), ft_strdup(cmd), '/'), false);
        err = check_exec(cmd_path, true);
        if (err.num == ENO_SUCCESS)
            return (t_path){(t_err){ENO_SUCCESS, 42, cmd_path}, cmd_path};
        i++;
    }
    return (t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL};
}

t_path get_path(char *cmd)
{
    char *value;

    if (!cmd[0])
        return (t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL};
    if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
        return (t_path){ft_check_exec(cmd, false), cmd};
    value = get_env("PATH");
    if (value)
        return get_env_path(value, cmd);
    return (t_path){(t_err){ENO_NOT_FOUND, ERRMSG_NO_SUCH_FILE, cmd}, NULL};
}
