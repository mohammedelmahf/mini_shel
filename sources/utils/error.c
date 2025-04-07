/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:17:10 by maelmahf          #+#    #+#             */
/*   Updated: 2025/04/07 09:21:40 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool    usage_message(bool return_valu)
{
    ft_putstr_fd("Usage: ./minishell\n" , 2);
    ft_putendl_fd("Usage: ./minishell -c \"input line\"\n", 2);
    return (return_valu);
}