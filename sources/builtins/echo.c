#include "../../includes/minishell.h"

int  parsinge_echo(char *str)
{
    int i ;
    
    i = 0;
    if(str[0] != '-')
        return (0);
    i++;
    while(str[i])
    {
        if(str[i] != 'n')
            return (0);
        i++;
    }
    return (1);
}

int	ft_echo(char **str)
{
    int i;
    int n;

    i = 1;
    n = 0;
    while(str[i] && (parsinge_echo(str[i]) == 1))
    {
        n = 1;
        i++;
    }
    while(str[i])
    {
        ft_putstr_fd(str[1] , 1);
        if(str[i] + 1)
            ft_putstr_fd(" " , 1);
        i++;
    }
    if(n == 0)
        ft_putstr_fd("\n" , 1);
    return (0);
}