/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:41:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/27 09:32:22 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	skip_word(char *str, size_t *i)
{
	char	quotes;

	while (str[*i] && str[*i] != ' ')
	{
		if (str[*i] != '\'' && str[*i] != '"')
			(*i)++;
		else
		{
			quotes = str[(*i)++];
			while (str[*i] && str[*i] != quotes)
				(*i)++;
			if (str[*i] == quotes)  // Found closing quote
				(*i)++;
		}
	}
}

// Helper function to calculate the actual length needed for a word
size_t	calculate_word_length(char *str, size_t start)
{
	size_t	i;
	size_t	len;
	char	quotes;

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
		{
			quotes = str[i++];
			len++;  // Count opening quote
			while (str[i] && str[i] != quotes)
			{
				len++;
				i++;
			}
			if (str[i] == quotes)
			{
				len++;  // Count closing quote
				i++;
			}
		}
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
			skip_word(str, &i);  // Move i to end of word
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
	strs[j][k] = '\0';  // Ensure null termination
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

char	**expander_split(char *str)
{
	size_t	count;
	char	**tofree;
	char	**strs;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && ++count)
			skip_word(str, &i);
		while (str[i] && str[i] == ' ')
			i++;
	}
	strs = ft_calloc(count + 1, sizeof(char *));
	tofree = strs;
	strs = allocater(str, strs);
	if (!strs || !count)
		return (free_char2(tofree), NULL);
	return (filler(str, strs));
}