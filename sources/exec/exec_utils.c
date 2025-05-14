/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:04:41 by maelmahf          #+#    #+#             */
/*   Updated: 2025/05/14 18:31:22 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_del(void *str)
{
	free(str);
	str = NULL;
}

void	*garbage_collector(char *str, bool clean)
{
	static t_list	*garbage_list;
	t_list			*new_node;

	if (clean)
	{
		if (garbage_list)
		{
			ft_lstclear(&garbage_list, ft_del);
			garbage_list = NULL;
		}
		return (NULL);
	}
	else if (str)
	{
		new_node = ft_lstnew(str);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&garbage_list, new_node);
		return (str);
	}
	return (NULL);
}

bool	is_delimiter(char *delimiter, char *str)
{
	while (*str)
	{
		if (*delimiter == '"' || *delimiter == '\'')
		{
			delimiter++;
			continue ;
		}
		else if (*str == *delimiter)
		{
			str++;
			delimiter++;
		}
		else
			return (false);
	}
	while (*delimiter == '"' || *delimiter == '\'')
		delimiter++;
	return (!*delimiter);
}
