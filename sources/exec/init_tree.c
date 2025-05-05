/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:36:49 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/05 11:36:10 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
static void	heredoc_sigint_handler(int signum)
{
	(void)signum;
	ft_clean_ms();
	exit(SIGINT);
}

void	heredoc(t_io_node *io, int p[2])
{
    
}

static bool	leave_leaf(int p[2], int *pid)
{
	waitpid(*pid, pid, 0);
	signal(SIGQUIT, handler_sigquit);
	data.signint_child = false;
	close(p[1]);
	if (WIFEXITED(*pid) && WEXITSTATUS(*pid) == SIGINT)
		return (true);
	return (false);
}

void    init_leaf(t_node *node)
{
    t_io_node	*io;
	int			p[2];
	int			pid;
    
    if(node->args)
        node->expanded_args = expand_args(node->args);
    io = node->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
		{
			pipe(p);
			data.signint_child = true;
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				heredoc(io, p);
			if (leave_leaf(p, &pid))
				return ;
			io->here_doc = p[0];
		}
		else
			io->expanded_value = expand(io->value);
		io = io->next;
	}
}

void    init_tree(t_node *node)
{
    if (!node)
        return ;
    if(node->type == N_PIPE 
        || node->type == N_AND
        || node->type == N_OR)
    {
        init_tree(node->left);
        if(!data.heredoc_sigint)
            init_tree(node->right);
    }
    else    
        init_leaf(node);
}

