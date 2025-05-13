/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_empty_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:34:47 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/13 18:54:12 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	is_empty_quote_pair(const char *s)
{
	return ((s[0] == '\'' && s[1] == '\'' && !s[2])
		|| (s[0] == '"' && s[1] == '"' && !s[2]));
}

static void	copy_without_empty_quotes(char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if ((src[i] == '\'' && src[i + 1] == '\'')
			|| (src[i] == '"' && src[i + 1] == '"'))
			i += 2;
		else
			dst[j++] = src[i++];
	}
	dst[j] = '\0';
}

char	*remove_empty_quotes(char *str)
{
	char	*tmp;
	char	*result;

	if (is_empty_quote_pair(str))
		return (str);
	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!tmp)
	{
		free(str);
		return (NULL);
	}
	copy_without_empty_quotes(tmp, str);
	result = ft_strdup(tmp);
	free(tmp);
	free(str);
	return (result);
}
