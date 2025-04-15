/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:02:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/15 11:13:55 by maelmahf         ###   ########.fr       */
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
            (/*clean_all(), */ft_putstr_fd("exit\n" , 1) , exit(data.exit_s));
        if(data.line[0])
            add_history(data.line);
        printf("Before tokenize\n");
        data.tokens = tokenize();
        printf("After tokenize\n");
        if (!data.tokens)
            continue;
        printf("Before start_parsing\n");
        data.ast = start_parsing();
        printf("After start_parsing\n");
        
        //printf("%s\n" ,data.line );
        //write(STDIN_FILENO, "hey", 4);
        //execution();
    }
    garbage_collector(NULL , true);

}