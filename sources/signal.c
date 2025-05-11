/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:40:08 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/11 21:17:04 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handler_sigint(int num)
{
	(void)num;
	if (g_data.signint_child)
	{
		ft_putstr_fd("\n", 1);
		g_data.signint_child = false;
		g_data.heredoc_sigint = true;
	}
	else
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_data.exit_s = 130;
	}
}

void	handler_sigquit(int num)
{
	(void)num;
	ft_putstr_fd("Quit: 3\n", 1);
}

void	init_signal(void)
{
	struct termios		term;

	term = g_data.original_term;
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	g_data.heredoc_sigint = false;
	g_data.signint_child = false;
	signal(SIGINT, handler_sigint);
	signal(SIGQUIT, SIG_IGN);
}
