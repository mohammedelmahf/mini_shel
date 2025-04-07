/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:17:10 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 11:09:26 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool    usage_message(bool return_valu)
{
    ft_putstr_fd("Usage: ./minishell\n" , 2);
    ft_putendl_fd("Usage: ./minishell -c \"input line\"\n", 2);
    return (return_valu);
}

static bool detail_quotes(char *cmd)
{
    if((ft_strncmp(cmd , "export" , 7) == 0) || (ft_strncmp(cmd ,"unset" , 6) == 0))
        return (true);
    return (false);
}

static  bool join_str(char *str , char *add)
{
    char *tmp;
    
    if(!add)
        return (str);
    if(!str)
        return (ft_strdup(add));
    tmp = str;
    str = ft_strjoin(tmp , add);
    free_ptr(tmp);
    return (str);
}

int error_msg_cmd(char *cmd , char *detail , char *error_message , int error_nb)
{
    char *msg;
    bool detail_quotes;

    detail_quotes = add_detail_quotes(cmd);
    msg = ft_strdup("minishell: ");
    if(cmd != NULL )
    {
        msg = join_str(msg, cmd);
        msg = join_str(msg, ": ");
    }
    if (detail != NULL)
	{
		if (detail_quotes)
			msg = join_str(msg, "`");
		msg = join_str(msg, detail);
		if (detail_quotes)
			msg = join_str(msg, "'");
		msg = join_str(msg, ": ");
	}
    msg = join_str(msg , error_message);
    ft_putstr_fd(msg , STDERR_FILENO);
    ft_putstr_fd("\n" ,STDERR_FILENO);
    free_ptr(msg);
    return (error_nb);
}