/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:02:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 20:06:32 by maelmahf         ###   ########.fr       */
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
    t_data  data;
    
    (void)ac;
    (void)av;
    init_minishell(env);
    while(1)
    {
        
    }
    start_execution();
}