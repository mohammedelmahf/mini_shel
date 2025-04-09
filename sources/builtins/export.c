#include "../../includes/minishell.h"

int parsinge_export(char *str)
{
    int i;
    i = 0;

    if(!str || ft_isalpha(str[i]))
        return 0;
    i = 1;
    while(str[i])
    {
        if(!ft_islnum(str[i]) && str[i] != '_')
            return 0;
        i++;
    }
    return 1 ;
}

void ft_export(char **str)
{
    if(str[1])
    {

    }
    if(parsinge_export(str) == 0)
    {
        //exit && msg
    }
    else
    {

    }
}