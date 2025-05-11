/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globber_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:34:32 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/11 21:11:36 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	len_arr(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**join_str_arr(char ***str)
{
	size_t	i;
	size_t	j;
	size_t	str_count;
	char	**joined;

	str_count = multi_str_count(str);
	joined = (char **)ft_calloc(str_count + 1, sizeof(char *));
	i = 0;
	str_count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			joined[str_count + j] = ft_strdup(str[i][j]);
			j++;
		}
		str_count += j;
		i++;
	}
	return (free_char3(str), joined);
}

size_t	multi_str_count(char ***str)
{
	size_t	i;
	size_t	j;
	size_t	str_count;

	i = 0;
	str_count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		str_count += j;
		i++;
	}
	return (str_count);
}

size_t	pattern_count(char *pattern)
{
	DIR				*dir;
	size_t			count;
	struct dirent	*entry;

	count = 0;
	dir = opendir(".");
	entry = readdir(dir);
	while (entry)
	{
		if (pattern_matches(pattern, entry->d_name))
			count++;
		entry = readdir(dir);
	}
	closedir(dir);
	return (count);
}

bool	contains_wildcard(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
			return (true);
		i++;
	}
	return (false);
}
