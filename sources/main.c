/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:02:17 by maelmahf          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/09 13:57:07 by iel-asef         ###   ########.fr       */
=======
/*   Updated: 2025/04/09 13:36:34 by maelmahf         ###   ########.fr       */
>>>>>>> 4258808c1b4333dc8bf03ec734b5e82aa37df292
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
            (/*clean_all(),*/ ft_putstr_fd("exit\n" , 1) , exit(data.exit_s));
        if(data.line[0])
            add_history(data.line);
            
        data.tokens = tokenize();
<<<<<<< HEAD
=======
            t_token *curr = data.tokens;
         while (curr)
        {
            printf("Token type: %d, Token value: %s\n", curr->type, curr->value);
            curr = curr->next;
        }
>>>>>>> 4258808c1b4333dc8bf03ec734b5e82aa37df292
        //if(!data.tokens)
        //    continue;
        // printf("%s\n" ,data.line );
        // write(STDIN_FILENO, "hey", 4);
        //execution();
    }

}