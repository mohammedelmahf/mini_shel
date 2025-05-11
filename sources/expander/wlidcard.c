/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlidcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:36:45 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/11 21:11:22 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_pattern_quotes(char **pattern, char *quotes)
{
	if (**pattern == '"' || **pattern == '\'')
	{
		if (*quotes)
			*quotes = *(*pattern)++;
		else
		{
			if (*quotes == **pattern)
			{
				*quotes = 0;
				(*pattern)++;
			}
		}
	}
}

bool	handle_stars(char **pattern, char **last_wildcard, char **last_match,
		char *str)
{
	while (**pattern == '*')
		(*pattern)++;
	if (!**pattern)
		return (true);
	*last_wildcard = *pattern;
	*last_match = str;
	return (false);
}

bool	pattern_match_exists(char **pattern, char **last_wildcard,
		char **last_match, char **str)
{
	if (**pattern == **str)
	{
		(*pattern)++;
		(*str)++;
		return (true);
	}
	else if (*last_wildcard)
	{
		*str = ++(*last_match);
		*pattern = *last_wildcard;
		return (true);
	}
	else
		return (false);
}

bool	pattern_matches(char *pattern, char *str)
{
	char	*last_wildcard;
	char	*last_match;
	char	quotes;

	quotes = 0;
	last_wildcard = NULL;
	last_match = NULL;
	while (*str)
	{
		handle_pattern_quotes(&pattern, &quotes);
		if (*pattern == '*' && !quotes && handle_stars(&pattern, &last_wildcard,
				&last_match, str))
			return (true);
		else if (!pattern_match_exists(&pattern, &last_wildcard, &last_match,
				&str))
			return (false);
	}
	if (*pattern == '*')
		while (*pattern == '*')
			pattern++;
	return (!*pattern);
}
