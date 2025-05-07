/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:02:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/07 09:15:14 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/minishell.h"

t_data	data;

static  void    init_minishell(char **env)
{
    ft_memset(&data , 0 , sizeof(data));
    data.environ = env;
    init_envlst();
    data.stdin = dup(0);
    data.stdout = dup(1);
	tcgetattr(STDIN_FILENO, &data.original_term);
}

void    execution(void)
{
    signal(SIGQUIT , handler_sigquit);
    init_tree(data.ast);
    if (data.heredoc_sigint)
	{
	    clear_ast(&data.ast);
		data.heredoc_sigint = false;
	}
    tcsetattr(STDIN_FILENO, TCSANOW, &data.original_term);
	data.exit_s = exec_node(data.ast, false);
	// clear_ast(&data.ast);
}

int main(int ac , char **av  , char **env)
{  
    (void)ac;
    (void)av;
    init_minishell(env);
    while(1)
    {
        init_signal();
        data.line = readline(PROMPT);
        if (!data.line)
            (clean_all(), ft_putstr_fd("exit\n" , 1) , exit(data.exit_s));
        if(data.line[0])
            add_history(data.line);
        if( ft_strcmp( data.line , "env") == 0)
	    {
		    ft_env();
	    }
        data.tokens = tokenize();
        if(!data.tokens)
            continue;
        data.ast = start_parsing();
        // if(data.parse_error.type)
        // {
        //     handle_parse_error();
        //     continue;
        // }
        execution();
    }
    garbage_collector(NULL , true);
    return (/*clean_all(),*/ data.exit_s);
}
