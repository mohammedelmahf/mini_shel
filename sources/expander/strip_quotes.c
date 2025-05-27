/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:28:18 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/27 14:04:55 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*strip_quotes(char *str)
{
	size_t	i = 0;
	size_t	j = 0;
	char	quote = 0;
	char	*res;
	size_t	len = ft_strlen(str);

	if ((len == 1) && (str[0] == '\'' || str[0] == '"'))
		return (gc_strdup(str));

	res = gc_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
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
	return (res);
}
