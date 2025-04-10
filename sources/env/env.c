/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:28:33 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/10 17:04:32 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *extract_key(char *str)
{
    size_t i;
    
    i = 0;
    while(str[i])
    {
        if(str[i] == '=')
            return (garbage_collector(ft_substr(str , 0 ,i) , false));
        i++;
    }
    return(ft_strdup(str));
}

char    *extract_value(char *str)
{
    size_t i;
    
    i = 0;
    while(str[i])
    {
        if(str[i] == '=')
        {
            i++;
            return (garbage_collector(ft_substr(str , i ,ft_strlen(str) - i) , false));
        }
        i++;
    }
    return(NULL);
}

void    init_envlst(void)
{
    int     i;
    char    **environ;
    char    *key;
    char    *value;

    environ = data.environ;
    if(!environ)
        return ;
    i = 0;
    // int j;
    // j = 0;
    while(environ[i])
    {
        // while(environ[j])
        // {
        //     printf("%s\n" , environ[j]);
        //     j++;  
        // }
        key = extract_key(environ[i]);
        value = extract_value(environ[i]);
        update_envlst(key, value, true);
        i++;
    }
}

int	ft_env(void)
{
	t_env	*list;

	list = data.envlst;
	while (list)
	{
		if (list->value != NULL)
			printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
	return (0);
}