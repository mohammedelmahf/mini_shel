/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:40:08 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/08 12:46:01 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void handler_sigint(int num)
{
    (void)num;
    if(data.signint_child)
    {
        ft_putstr_fd("\n",1);
        data.signint_child = false;
        data.heredoc_sigint = true;
    }
    else
    {
        ft_putstr_fd("\n" ,1);
        rl_replace_line("" , 0);
        rl_on_new_line();
        rl_redisplay();
    }
}

void    init_signal(void)
{
    struct termios term;

    term = data.original_term;
    term.c_lflag &= ~ECHOCTL;
    tcsetattr(STDIN_FILENO , TCSANOW , &term);
    data.heredoc_sigint = false;
    data.signint_child = false;
    signal(SIGINT , handler_sigint);
    signal(SIGQUIT, SIG_IGN);
}