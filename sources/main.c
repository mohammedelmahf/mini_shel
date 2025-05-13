/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:02:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/13 12:19:01 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_data	g_data;

static void	init_minishell(char **env)
{
	ft_memset(&g_data, 0, sizeof(g_data));
	g_data.environ = env;
	init_envlst();
	g_data.stdin = dup(0);
	g_data.stdout = dup(1);
	tcgetattr(STDIN_FILENO, &g_data.original_term);
}

void	execution(void)
{
	signal(SIGQUIT, handler_sigquit);
	init_tree(g_data.ast);
	if (g_data.heredoc_sigint)
	{
		g_data.exit_s = 130;
		clear_ast(&g_data.ast);
		g_data.heredoc_sigint = false;
		return ;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &g_data.original_term);
	g_data.exit_s = exec_node(g_data.ast, false);
	clear_ast(&g_data.ast);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	init_minishell(env);
	while (1)
	{
		init_signal();
		g_data.line = readline(PROMPT);
		if (!g_data.line)
			(clean_all(), ft_putstr_fd("exit\n", 1), exit(g_data.exit_s));
		if (g_data.line[0])
			add_history(g_data.line);
		g_data.tokens = tokenize();
		if (!g_data.tokens)
			continue ;
		g_data.ast = start_parsing();
		if (g_data.parse_error.type)
		{
			handle_parse_error();
			continue ;
		}
		execution();
	}
	garbage_collector(NULL, true);
	return (clean_all(), g_data.exit_s);
}
