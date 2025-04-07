/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:02:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 10:01:57 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/minishell.h"

static bool start_check(t_data *data, int ac , char **av)
{
    if(ac != 1 && ac != 3)
        return (usage_message(false));
    if(ac == 3)
    {
        data->interactive = false;
        if(!av[1] || (av[1] && ft_strcmp(av[1] , "-c") != 0))
            return (usage_message(false));
        if(!av[2] || (av[2] && av[2][0] == '\0'))
            return (usage_message(false));
    }
    else
        data->interactive = true;
    return (true);
}
int main(int ac , char **av , char **env)
{
    t_data data;
    
    if(!start_check(&data , ac , av) || !init_data(&data , env))
        exit_shell();
}