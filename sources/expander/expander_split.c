/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:41:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/28 09:56:02 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	skip_quoted_segment(char *str, size_t i, size_t *len)
{
	char	quotes;

	quotes = str[i++];
	(*len)++;
	while (str[i] && str[i] != quotes)
	{
		(*len)++;
		i++;
	}
	if (str[i] == quotes)
	{
		(*len)++;
		i++;
	}
	return (i);
}

size_t	calculate_word_length(char *str, size_t start)
{
	size_t	i;
	size_t	len;

	i = start;
	len = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] != '\'' && str[i] != '"')
		{
			len++;
			i++;
		}
		else
			i = skip_quoted_segment(str, i, &len);
	}
	return (len);
}

char	**allocater(char *str, char **strs)
{
	size_t	start;
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			start = i;
			word_len = calculate_word_length(str, start);
			strs[j] = ft_calloc(word_len + 1, sizeof(char));
			if (!strs[j])
				return (NULL);
			skip_word(str, &i);
			j++;
		}
		while (str[i] && str[i] == ' ')
			i++;
	}
	return (strs);
}

void	word_filler(const char *str, char **strs, size_t *i, size_t j)
{
	char	quotes;
	size_t	k;

	k = 0;
	while (str[(*i)] && str[(*i)] != ' ')
	{
		if (str[(*i)] != '\'' && str[(*i)] != '"')
			strs[j][k++] = str[(*i)++];
		else
		{
			quotes = str[(*i)++];
			strs[j][k++] = quotes;
			while (str[(*i)] && str[(*i)] != quotes)
				strs[j][k++] = str[(*i)++];
			if (str[(*i)] == quotes)
				strs[j][k++] = str[(*i)++];
		}
	}
	strs[j][k] = '\0';
}

char	**filler(char *str, char **strs)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && strs[j])
	{
		if (str[i] != ' ')
		{
			word_filler(str, strs, &i, j);
			j++;
		}
		while (str[i] && str[i] == ' ')
			i++;
	}
	return (strs);
}
