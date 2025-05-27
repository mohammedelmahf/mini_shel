/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:28:18 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/27 10:54:11 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char *gc_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (gc_strdup(""));
	substr = gc_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}


char	*strip_quotes(char *str)
{
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);

	if (len >= 2 && ((str[0] == '\'' && str[len - 1] == '\'') ||
					 (str[0] == '"' && str[len - 1] == '"')))
	{
		char	*new_str = gc_substr(str, 1, len - 2);
		return (new_str);
	}
	return (str);
}

// static size_t	unquoted_strlen(char *str)
// {
// 	size_t	i;
// 	size_t	len;
// 	char	quotes;

// 	i = 0;
// 	len = 0;
// 	quotes = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\'' || str[i] == '"')
// 		{
// 			if (!quotes)
// 				quotes = str[i++];
// 			else if (str[i] == quotes)
// 				quotes = ((i++) && 0);
// 			else
// 				len += (i++ || 1);
// 		}
// 		else
// 			len += (i++ || 1);
// 	}
// 	return (len);
// }

// static void	unquote_filler(char *str, size_t *i, char *ret, size_t *j)
// {
// 	char	quotes;

// 	quotes = str[(*i)++];
// 	while (str[*i] && str[*i] != quotes)
// 		ret[(*j)++] = str[(*i)++];
// 	if (str[*i] == quotes)
// 		(*i)++;
// }

// char	*strip_quotes(char *str)
// {
// 	char	*ret;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	ret = gc_calloc(1 + unquoted_strlen(str), sizeof(char));
// 	if (!ret)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		if (str[i] == '"' || str[i] == '\'')
// 			(unquote_filler(str, &i, ret, &j));
// 		else
// 			ret[j++] = str[i++];
// 	}
// 	return (ret);
// }
