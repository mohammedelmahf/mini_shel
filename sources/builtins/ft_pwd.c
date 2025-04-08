#include"../../includes/minishell.h"

int  ft_pwd (void)
{
    char pwd[PATH_MAX];
    
    if(getcwd(pwd , PATH_MAX))
    {
        printf("%s\n", pwd);
        return (0);
    }
    else
    {
        perror("pwd");
        return (1);
    }
}