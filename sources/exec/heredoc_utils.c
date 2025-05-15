/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:45:36 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/15 08:45:43 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	heredoc_sigint_handler(int signum)
{
	(void)signum;
	clean_all();
	exit(SIGINT);
}

static void	print_eof_warning(char *value)
{
	ft_putstr_fd("bash: warning: here-document at line 1 ", 2);
	ft_putstr_fd("delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(value, 2);
	ft_putstr_fd("')\n", 2);
}

static void	write_line_to_pipe(char *line, int fd, bool expand)
{
	if (expand)
		heredoc_expander(line, fd);
	else
	{
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
	}
}

static void	heredoc_loop(t_io_node *io, int p[2], char *quotes)
{
	char	*line;
	int		delimiter_found;

	delimiter_found = 0;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			if (!delimiter_found)
				print_eof_warning(io->value);
			break ;
		}
		if (is_delimiter(io->value, line))
		{
			free(line);
			delimiter_found = 1;
			break ;
		}
		write_line_to_pipe(line, p[1], !*quotes);
		free(line);
	}
}

void	heredoc(t_io_node *io, int p[2])
{
	char	*quotes;

	signal(SIGINT, heredoc_sigint_handler);
	quotes = io->value;
	while (*quotes && *quotes != '"' && *quotes != '\'')
		quotes++;
	heredoc_loop(io, p, quotes);
	clean_all();
	exit(0);
}
