/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:02:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/05 01:11:39 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/minishell.h"

t_data	data;

// static  void    init_minishell(char **env)
// {
//     ft_memset(&data , 0 , sizeof(data));
//     data.environ = env;
//     init_envlst();
//     data.stdin = dup(0);
//     data.stdout = dup(1);
// 	tcgetattr(STDIN_FILENO, &data.original_term);
// }

// void    execution(void)
// {
//     signal(SIGQUIT , handler_sigquit);
//     init_tree(data.ast);
// }

// int main(int ac , char **av  , char **env)
// {  
//     (void)ac;
//     (void)av;
//     init_minishell(env);
//     while(1)
//     {
//         init_signal();
//         data.line = readline(PROMPT);
//         if (!data.line)
//             (/*clean_all(), */ft_putstr_fd("exit\n" , 1) , exit(data.exit_s));
//         if(data.line[0])
//             add_history(data.line);
//         printf("Before tokenize\n");
//         data.tokens = tokenize();
//             t_token *curr = data.tokens;
 
//         while (curr)
//         {
//             printf("Token type: %d, Token value: %s\n", curr->type, curr->value);
//             curr = curr->next;
//         }
//         if(!data.tokens)
//             continue;
//         printf("Before start_parsing\n");
//         data.ast = start_parsing();
//         printf("After start_parsing\n");
//         // if(data.parse_error.type)
//         // {
//         //     handle_parse_error();
//         //     continue;
//         // }
//         printf("data_ast : %p\n" , data.ast);
//         //write(STDIN_FILENO, "hey", 4);
//         execution();
//     }
//     garbage_collector(NULL , true);

// }
#include "../includes/minishell.h"

t_data	data;

static void	init_minishell(char **env)
{
	ft_memset(&data, 0, sizeof(data));
	data.environ = env;
	init_envlst(); // كتدير parsing ديال env
	data.stdin = dup(0);
	data.stdout = dup(1);
	tcgetattr(STDIN_FILENO, &data.original_term);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	init_minishell(env);

	while (1)
	{
		init_signal();
		data.line = readline("minishell> ");
		if (!data.line)
		{
			ft_putstr_fd("exit\n", 1);
			exit(data.exit_s);
		}
		// if (data.line[0])
		// 	add_history(data.line);

		// data.tokens = tokenize();
		// if (!data.tokens)
		// {
		// 	free(data.line);
		// 	continue;
		// }

	if( ft_strcmp( data.line , "cd") == 0)
	{
		ft_export(&data.line);
	}
	}
	garbage_collector(NULL, true);
	return (0);
}
