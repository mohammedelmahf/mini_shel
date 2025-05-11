/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:28:33 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/11 01:08:35 by iel-asef         ###   ########.fr       */
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

// void    init_envlst(void)
// {
//     int     i;
//     char    **environ;
//     char    *key;
//     char    *value;

//     environ = g_data.environ;
//     if(!environ)
//         return ;
//     i = 0;
//     while(environ[i])
//     {
//         key = extract_key(environ[i]);
//         value = extract_value(environ[i]);
//         update_envlst(key, value, true);
//         i++;
//     }
// }
void init_envlst(void)
{
    int     i;
    char    **environ;
    char    *key;
    char    *value;
    char    cwd[1024];

    environ = g_data.environ;
    g_data.envlst = NULL;
    
    if (!environ || !environ[0])
    {
        if (getcwd(cwd, sizeof(cwd)))
        {
            update_envlst(ft_strdup("PWD"), ft_strdup(cwd), true);
            update_envlst(ft_strdup("OLDPWD"), ft_strdup(cwd), true);
        }

        update_envlst(ft_strdup("SHLVL"), ft_strdup("1"), true);
        update_envlst(ft_strdup("PATH"), ft_strdup("/bin:/usr/bin:/usr/local/bin"), true);
        
        return;
    }

    i = 0;
    while (environ[i])
    {
        key = extract_key(environ[i]);
        value = extract_value(environ[i]);
        update_envlst(key, value, true);
        i++;
    }
}
