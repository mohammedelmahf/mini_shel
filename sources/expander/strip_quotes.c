/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:28:18 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/28 10:00:18 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	copy_without_quotes(char *res, char *str)
{
	size_t	i;
	size_t	j;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && quote == 0)
			quote = str[i++];
		else if (str[i] == quote)
		{
			quote = 0;
			i++;
		}
		else
			res[j++] = str[i++];
	}
}

char	*strip_quotes(char *str)
{
	size_t	len;
	char	*res;

	len = ft_strlen(str);
	if ((len == 1) && (str[0] == '\'' || str[0] == '"'))
		return (gc_strdup(str));
	res = gc_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	copy_without_quotes(res, str);
	return (res);
}

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
			if (str[*i] == quotes)
				(*i)++;
		}
	}
}
