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
    t_err err;
    char *value;

    if (!cmd || !cmd[0])
        return (t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL};

    if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
    {
        err = check_exec(cmd, false);
        return (t_path){err, cmd};
    }

    value = getenv("PATH");
    if (value)
        return get_env_path(value, cmd);

    return (t_path){(t_err){ENO_NOT_FOUND, ERRMSG_NO_SUCH_FILE, cmd}, NULL};
}
