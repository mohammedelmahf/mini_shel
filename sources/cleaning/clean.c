/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:39:18 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/10 12:20:42 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


static  void    clear_envlst(void)
{
    t_env   *envlst;
    t_env   *envlst_tofree;
    
    envlst = g_data.envlst;
    while(envlst)
    {
        envlst_tofree = envlst;
        envlst = envlst->next;
        free(envlst_tofree);
    }
    g_data.envlst = NULL;
}
void    clean_all(void)
{
    garbage_collector(NULL , true);
    clear_ast(&g_data.ast);
    clear_envlst();
    rl_clear_history();
    tcsetattr(STDIN_FILENO, TCSANOW, &g_data.original_term);
}