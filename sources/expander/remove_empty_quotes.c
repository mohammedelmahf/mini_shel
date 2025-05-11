/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_empty_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:34:47 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/29 09:37:04 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*remove_empty_quotes(char *str)
{
	size_t	src_i;
	size_t	dst_i;
	char	*scratch_buffer;
	char	*cleaned_str;
	size_t	final_len;

	if ((str[0] == '\'' && str[1] == '\'' && !str[2]) || (str[0] == '"'
			&& str[1] == '"' && !str[2]))
		return (str);
	scratch_buffer = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	src_i = 0;
	dst_i = 0;
	while (str[src_i])
	{
		if ((str[src_i] == '\'' && str[src_i + 1] == '\'') || (str[src_i] == '"'
				&& str[src_i + 1] == '"'))
			src_i += 2;
		else
			scratch_buffer[dst_i++] = str[src_i++];
	}
	free(str);
	final_len = ft_strlen(scratch_buffer) + 1;
	cleaned_str = ft_calloc(final_len, sizeof(char));
	ft_strlcpy(cleaned_str, scratch_buffer, final_len);
	free(scratch_buffer);
	return (cleaned_str);
}
