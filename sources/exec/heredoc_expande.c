/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expande.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:24:45 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/15 08:53:21 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	heredoc_expand_writer(char *str, size_t i, int fd)
{
	size_t	start;
	char	*tmp;

	start = ++i;
	if (str[i] == '?')
		return (ft_putnbr_fd(g_data.exit_s, fd), 2);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (i != start)
	{
		tmp = garbage_collector(ft_substr(str, start, i - start), false);
		tmp = get_envlst_value(tmp);
		if (tmp)
			ft_putstr_fd(tmp, fd);
	}
	return (i);
}

static void	write_prefix(char *str, size_t start, size_t end, int fd)
{
	char	*prefix;

	prefix = ft_substr(str, start, end - start);
	ft_putstr_fd(prefix, fd);
	free(prefix);
}

void	heredoc_expander(char *str, int fd)
{
	size_t	i;
	size_t	consumed;
	size_t	start;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (i > start)
				write_prefix(str, start, i, fd);
			consumed = heredoc_expand_writer(str, i, fd);
			i += consumed;
			start = i;
		}
		else
			i++;
	}
	if (i > start)
		write_prefix(str, start, i, fd);
	ft_putchar_fd('\n', fd);
}
