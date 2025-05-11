/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expande.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:24:45 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/11 17:04:37 by maelmahf         ###   ########.fr       */
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

void	heredoc_expander(char *str, int fd)
{
	size_t	i;
	size_t consumed;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (i > 0)
			{
				char *prefix = ft_substr(str, 0, i);
				ft_putstr_fd(prefix, fd);
				free(prefix);
			}
			consumed = heredoc_expand_writer(str, i, fd);
			str += consumed;
			i = 0;
		}
		else
			i++;
	}
	if (*str)
		ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}