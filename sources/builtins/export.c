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
        {
            ft_putstr_fd("minishell: export: `%s`: not a valid identifier\n", 2);
            exit_s = 1;
        }
        else
        {
            key = extract_key(str);
            if(1)
            {
                update_envlst(key ,extract_value(str[i]) , false); //false  = update
            }
            else
                 update_envlst(key ,extract_value(str[i]) , true); //true = add
        }
    }
    return exit_s;
}