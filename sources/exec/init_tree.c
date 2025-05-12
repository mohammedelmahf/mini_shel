/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:36:49 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/12 14:53:27 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	heredoc_sigint_handler(int signum)
{
	(void)signum;
	clean_all();
	exit(SIGINT);
}

void heredoc(t_io_node *io, int p[2])
{
    char *line;
    char *quotes;
    int delimiter_found = 0;

    signal(SIGINT, heredoc_sigint_handler); // handle Ctrl+C during heredoc
    quotes = io->value;

    // Check if delimiter contains quotes and handle accordingly
    while (*quotes && *quotes != '"' && *quotes != '\'')
        quotes++;

    while (1)
    {
        line = readline("> ");  // Read input from user
        
        // If EOF (Ctrl+D) is encountered, break the loop
        if (!line)
        {
            // If we haven't found the delimiter, issue a warning
            if (!delimiter_found)
            {
                ft_putstr_fd("bash: warning: here-document at line 1 delimited by end-of-file (wanted `", 2);
                ft_putstr_fd(io->value, 2);
                ft_putstr_fd("')\n", 2);
            }
            break;
        }

        // Check if the line exactly matches the delimiter
        if (is_delimiter(io->value, line))
        {
            free(line); // Free the line if delimiter is matched
            delimiter_found = 1;
            break; // Exit the heredoc loop
        }

        // Handle variable expansion if there are no quotes in the delimiter
        if (!*quotes)
            heredoc_expander(line, p[1]);
        else
        {
            ft_putstr_fd(line, p[1]);
            ft_putstr_fd("\n", p[1]);
        }

        free(line); // Free the line after processing
    }

    clean_all(); // Clean up resources
    exit(0);     // Exit the heredoc process
}


static bool	leave_leaf(int p[2], int *pid)
{
	waitpid(*pid, pid, 0);
	signal(SIGQUIT, handler_sigquit);
	g_data.signint_child = false;
	close(p[1]);
	if (WIFEXITED(*pid) && WEXITSTATUS(*pid) == SIGINT)
		return (true);
	return (false);
}

void	init_leaf(t_node *node)
{
	t_io_node	*io;
	int			p[2];
	int			pid;

	io = node->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
		{
			pipe(p);
			g_data.signint_child = true;
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				heredoc(io, p);
			if (leave_leaf(p, &pid))
				return ;
			io->here_doc = p[0];
		}
		else
			io->expanded_value = expand_args(io->value);
		io = io->next;
	}
}

void	init_tree(t_node *node)
{
	if (!node)
		return ;
	if (node->type == N_PIPE || node->type == N_AND || node->type == N_OR)
	{
		init_tree(node->left);
		if (!g_data.heredoc_sigint)
			init_tree(node->right);
	}
	else
		init_leaf(node);
}
