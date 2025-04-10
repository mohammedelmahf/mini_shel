/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:39:26 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/10 11:23:20 by maelmahf         ###   ########.fr       */
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

bool    skip_delimiter