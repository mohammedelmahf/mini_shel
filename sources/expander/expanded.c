/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:00:58 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/11 09:42:44 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char *handle_dollar(char *str, size_t *i)
// {
//     char *result = ft_strdup("");
//     char *tmp;

//     while (str[*i] == '$') {
//         (*i)++;
//         if (!str[*i]) {
//             tmp = ft_strdup("$");
//         }
//         else if (str[*i] == '$') {
//             (*i)++;
//             tmp = ft_itoa(getpid());
//         }
//         // $? → last exit status
//         else if (str[*i] == '?') {
//             (*i)++;
//             tmp = ft_itoa(g_data.exit_s);
//         }
//         // $1, $@, etc → unsupported
//         else if (ft_isdigit(str[*i]) || str[*i] == '@') {
//             (*i)++;
//             tmp = ft_strdup("");
//         }
//         // $ followed by invalid char (space, etc.) → literal $
//         else if (!is_valid_var_char(str[*i]))
//         {
//             if (str[*i] == '\0')
//                 tmp = ft_strdup("");      // End of string after $
//             else if (str[*i] == '$')
//                 tmp = ft_itoa(getpid());  // Handle $$ (already above, but safe here)
//             else
//                 tmp = ft_strdup("");      // Invalid var character → expand to ""
//         }
//         // $VAR → lookup
//         else
//         {
//             size_t start = *i;
//             while (is_valid_var_char(str[*i]))
//                 (*i)++;
//             char *var = ft_substr(str, start, *i - start);
//             char *val = get_envlst_value(var);
//             tmp = ft_strdup(val ? val : "");
//             free(var);
//         }

//         result = ft_strjoin_f(result, tmp);  // joins and frees old result
//     }

//     return result;
// }


char *handle_dollar(char *str, size_t *i)
{
    size_t start;
    char *var;
    char *env_value;

    (*i)++;

    if (str[*i] == '\0')  
        return (ft_strdup("$"));

    if (str[*i] == '?')
    {
        (*i)++;
        return (ft_itoa(g_data.exit_s));
    }
    else if (str[*i] == '!')
    {
        (*i)++;
        return (ft_strdup(""));
    }
    else if (!is_valid_var_char(str[*i]))
        return (ft_strdup("$"));

    start = *i;
    while (is_valid_var_char(str[*i]))
        (*i)++;

    var = ft_substr(str, start, *i - start);
    env_value = get_envlst_value(var);
    free(var);

    if (!env_value)
        return (ft_strdup(""));
    
    return (ft_strdup(env_value));
}



char    *cmd_pre_expand(char *str)
{
    char *expanded;
    size_t i;

    expanded = ft_strdup("");
    i = 0;
    while(str[i])
    {
        if(str[i]  == '\'')
            expanded = ft_strjoin_f(expanded , handle_squotes(str , &i));
        else if(str[i] == '"')
            expanded = ft_strjoin_f(expanded , handle_dquotes(str , &i));
        else if(str[i] == '$')
            expanded = ft_strjoin_f(expanded , handle_dollar(str , &i));
        else
            expanded = ft_strjoin_f(expanded , handle_normal_str(str , &i));
    }
    return (expanded);
}

char    **expand_args(char *str)
{
    char    **expanded;
    char    **globbed;
    size_t  i;
    str = cmd_pre_expand(str);
    if(!str)
        return (NULL);
    str = remove_empty_quotes(str);
    if(!str)
        return (NULL);
    expanded = expander_split(str);
    free(str);
    if(!expanded)
        return (NULL);
    globbed = globber(expanded);
    if(!globbed)
        return (NULL);
    i = 0;
    while(globbed[i])
    {
        globbed[i] = strip_quotes(globbed[i]);
        i++;
    }
    return (globbed);
}