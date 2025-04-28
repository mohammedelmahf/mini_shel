#include "../../includes/minishell.h"

static t_path get_env_path(char *path, char *cmd)
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

// void execute_cmd(char **args, char **envp)
// {
//     if (!args || !args[0] || args[0][0] == '\0')
//         return;
//     if (is_builtin(args[0]))
//     {
//         exec_builtins(args);
//         return;
//     }
//     t_path p = get_path(args[0]);
//     if (p.err.num != ENO_SUCCESS)
//     {
//         ft_putstr_fd("minishell: ", 2);
//         ft_putstr_fd(p.err.cause, 2);
//         ft_putstr_fd(": command not found\n", 2);
//         return;
//     }
//     pid_t pid = fork();
//     if (pid == 0)
//     {
//         execve(p.path, args, envp);
//         perror("execve");
//         exit(EXIT_FAILURE);
//     }
//     else if (pid > 0)
//         waitpid(pid, NULL, 0);
//     else
//         perror("fork");
// }
