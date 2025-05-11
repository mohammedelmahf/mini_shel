/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:28:33 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/11 10:39:44 by iel-asef         ###   ########.fr       */
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
// void init_envlst(void)
char *ft_itoa_simple(int n)
{
    char    *str;
    long    nbr;
    size_t  size;

    nbr = n;
    size = (nbr <= 0) ? 1 : 0;
    if (nbr < 0)
    {
        nbr = -nbr;
        size++;
    }
    while (n)
        n = n / 10 + (size++ * 0);
    str = (char *)malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    *(str + size--) = '\0';
    *(str + size--) = nbr % 10 + '0';
    while (nbr /= 10)
        *(str + size--) = nbr % 10 + '0';
    if (size == 0 && str[1] == '\0')
        *(str + size) = '0';
    else if (size == 0 && str[1] != '\0')
        *(str + size) = '-';
    return (str);
}

// /**
//  * Creates a new environment variable node
//  */
// t_env *envlst_new(char *key, char *value)
// {
//     t_env *new;

//     new = (t_env *)malloc(sizeof(*new));
//     if (!new)
//         return (NULL);
//     new->key = key;
//     new->value = value;
//     new->next = NULL;
//     return (new);
// }
void init_envlst(void)
{
    int     i;
    char    **environ;
    char    *key;
    char    *value;
    char    cwd[PATH_MAX];

    // First clear any existing environment list
    // (This function should be implemented if you need to reinit)
    // clear_envlst();
    
    g_data.envlst = NULL;
    environ = g_data.environ;
    
    // Initialize from environ if available
    if (environ)
    {
        i = 0;
        while (environ[i])
        {
            key = extract_key(environ[i]);
            value = extract_value(environ[i]);
            update_envlst(key, value, true);
            i++;
        }
    }
     // Set OLDPWD if it doesn't exist (as empty like bash does)
    if (!get_env("OLDPWD"))
        update_envlst(ft_strdup("OLDPWD"), NULL, true);
    
    // Set _ to path of shell
    update_envlst(ft_strdup("_"), ft_strdup("./minishell"), true);
    
    // Ensure PWD is set
    if (!get_env("PWD"))
    {
        if (getcwd(cwd, sizeof(cwd)))
            update_envlst(ft_strdup("PWD"), ft_strdup(cwd), true);
        else
            update_envlst(ft_strdup("PWD"), ft_strdup("/"), true);
    }
    
    // Handle SHLVL (set to 1 if not exists, increment if exists)
    t_env *shlvl = get_env("SHLVL");
    if (!shlvl)
    {
        update_envlst(ft_strdup("SHLVL"), ft_strdup("1"), true);
    }
    // else if (shlvl->value)
    // {
    //     int level = ft_atoi(shlvl->value);
    //     // Check for invalid SHLVL and reset if needed
    //     if (level < 0 || !ft_isnumber(shlvl->value))
    //         level = 0;
    //     level++; // Increment level
    //     if (level > 999) // Bash resets to 1 if level > 999
    //         level = 1;
    //     update_envlst(ft_strdup("SHLVL"), ft_itoa_simple(level), false);
    // }
    // else
    // {
    //     update_envlst(ft_strdup("SHLVL"), ft_strdup("1"), false);
    // }
    
    // Set OLDPWD if it doesn't exist (as empty like bash does)
    if (!get_env("OLDPWD"))
        update_envlst(ft_strdup("OLDPWD"), NULL, true);
    
    // Set _ to path of shell
    update_envlst(ft_strdup("_"), ft_strdup("./minishell"), true);
}