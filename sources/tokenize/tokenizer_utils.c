/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:39:26 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/10 11:31:55 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_is_separator(char *str)
{
    if(!ft_strncmp(str , "&&" , 2) || *str == ' ' || *str == '\t' 
            || *str == '>' || *str == '<' || *str == '|' || *str == ')' || *str == ')')
        return (1);
    return (0);
}

int check_is_string_delimiter(char c)
{
    if(c == '\'' || c == '"')
        return (1);
    return (0);
}

bool    skip_delimiter(char *line , size_t *i)
{
    char delimiter;

    delimiter = line[*i];

    if(ft_strchr(line + *i + 1 , delimiter))
    {
        (*i)++;
        while(line[*i] != delimiter)
            (*i)++;
        (*i)++;
        return (true);
    }
    return (false);
}