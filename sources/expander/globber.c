/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globber.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:32:33 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/05 09:44:48 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    **globber_helper(char **str)
{
    char    *returned;
    DIR     *dir;
    size_t  match_count;
    struct dirent   *entry;

    match_count = pattern_count(str);
    
}

char    **globber(char **expanded)
{
    char    ***globbed;
    size_t  expanded_len;
    size_t  i;

    i = 0;
    expanded_len = len_arr(expanded);
    globbed = (char ***)ft_calloc(expanded_len + 1 , sizeof(char **));
    while(expanded[i])
    {
        globbed[i] = globber_helper(expanded[i]);
        i++;
    }
    return (free_spliter2(expanded) , join_str_arr(globbed));
}