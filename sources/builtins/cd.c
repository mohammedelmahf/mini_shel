#include "../../includes/minishell.h"

int ft_cd(char **args)
{
    char *path;
    char *oldpwd;
    char *cwd;

    if (!args[1])
        path = getenv("HOME");
    else if (!ft_strcmp(args[1], "-"))
        path = ft_getenv("OLDPWD");
    else
        path = args[1];

    if (!path)
    {
        printf("minishell: cd: path not set\n");
        return 1;
    }
    oldpwd = ft_getenv("PWD");

    if (chdir(path) == -1)
    {
        perror("minishell: cd");
        return 1;
    }
    update_envlst("OLDPWD", oldpwd, true);
    cwd = getcwd(NULL, 0);
    update_envlst("PWD", cwd, true);
    free(cwd);

    return 0;
}
