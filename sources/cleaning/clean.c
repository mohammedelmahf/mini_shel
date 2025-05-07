/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:39:18 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/07 09:15:38 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


static  void    clear_envlst(void)
{
    t_env   *envlst;
    t_env   *envlst_tofree;
    
    envlst = data.envlst;
    while(envlst)
    {
        envlst_tofree = envlst;
        envlst = envlst->next;
        free(envlst_tofree);
    }
    data.envlst = NULL;
}
void    clean_all(void)
{
    garbage_collector(NULL , true);
    clear_ast(&data.ast); //ast abstract synatx tree
    clear_envlst();
    rl_clear_history();
    tcsetattr(STDIN_FILENO, TCSANOW, &data.original_term);
}