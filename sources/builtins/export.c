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

int  ft_export(char **str)
{
    int i;
    int exit_s;
    char *key;

    exit_s = 0;
    if(str[1])
    {

    }
    i = 0;
    while(str[i])
    {
        if(parsinge_export(str[i]) == 0)
            //exit && msg
        else
        {
            key = extract_key(str);
            if( )
            {
                update_envlst(key ,extract_value(str[i]) , false);
            }
            else
                 update_envlst(key ,extract_value(str[i]) , true);
        }
    }
    return exit_s;
}