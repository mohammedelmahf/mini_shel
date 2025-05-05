/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globber.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:32:33 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/05 10:58:45 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	matches_visibility(char *pattern, char *str)
{
	if ((pattern[0] == '.' && str[0] == '.')
		|| (pattern[0] != '.' && str[0] != '.'))
		return (true);
	return (false);
}

static bool	set_direntry(struct dirent **entry, DIR *dir)
{
	*entry = readdir(dir);
	return (true);
}

char    **globber_helper(char *str)
{
    char    **returned;
    DIR     *dir;
    size_t  match_count;
    struct dirent   *entry;

    match_count = pattern_count(str);
    if(!contains_wildcard(str) || !match_count)
    {
        returned = (char **)ft_calloc(2 , sizeof(char *));
        returned[0] = ft_strdup(str);
        return (returned);
    }
    else
    {
        dir = opendir(".");
        returned = (char **)ft_calloc(match_count + 1 , sizeof(char *));
        match_count = 0;
        while(set_direntry(&entry , dir) && entry)
            if(pattern_matches(str , entry->d_name) && matches_visibility(str , entry->d_name))
                returned[match_count++] = ft_strdup(entry->d_name);
        closedir(dir);
    }
    return (returned);
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
    return (free_char2(expanded) , join_str_arr(globbed));
}