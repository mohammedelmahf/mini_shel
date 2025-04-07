/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:02:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 15:29:03 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/minishell.h"

int main(int ac , char **av  , char **env)
{
    t_data  data;
    
    (void)ac;
    (void)av;
    data.in = dup(STDIN);
    data.out = dup(STDOUT);
    data.exit = 0;
    data.ret = 0;
    data.no_exec = 0;
    rest_fd(&data);
    init_env(&data , env);
}