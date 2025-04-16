#include "../../includes/minishell.h"


void msg_err(char *s)
{
    ft_putstr_fd ("minishell: export:" , 2);
    ft_putstr_fd (s , 2);
    ft_putstr_fd (": not a valid identifier\n", 2); 
}

void ft_unset_help(char *key)
{
    t_env *current;
    t_env *prev;

    prev = NULL;
    current = data.envlst;

    while(current)
    {
        if(!ft_strcmp( key , current->key))
        {
            if(prev)
                prev->next = current->next;
            else
                data.envlst = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int ft_unset(char **s)
{   
    int i;
    bool err;
    char *key;

    key = garbage_collector(extract_key(s[i]) , false);
    i = 0;
    while(s[i])
    {
        if (!parsing_key(s[i]))
        {
            msg_err(s[i]);
            err = true;
        }
        else
            ft_unset_help(key);
        i++;
    }

}