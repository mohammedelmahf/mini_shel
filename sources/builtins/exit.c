#include "../../includes/minishell.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

bool ft_isnumber(char *s)
{
    int i = 0;

    if (s[i] == '-' || s[i] == '+')
        i++;
    
    if (!s[i])
        return (false);
    while (s[i])
    {
        if (!ft_isdigit(s[i]))
            return (false);
        i++;
    }
    return (true);
}

int ft_exit(char **s)
{
    int exit_s;

    printf("exit\n");
    if (!s[1])
    {
        exit(data.exit_s);
    }
    if (!ft_isnumber(s[1]))
    {
        ft_putstr_fd("minishell: exit: ", 2);
        ft_putstr_fd(s[1], 2);
        ft_putstr_fd(": numeric argument required\n", 2);
        exit(255);
    }
    if (s[2] != NULL)
    {
        ft_putstr_fd("minishell: exit: too many arguments\n", 2);
        data.exit_s = 1;
        return (1); 
    }
    exit_s = ft_atoi(s[1]);
    exit_s = exit_s % 256;
    if (exit_s < 0)
        exit_s += 256;
    exit(exit_s);
}