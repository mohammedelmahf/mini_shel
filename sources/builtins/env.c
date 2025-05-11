/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:13 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/11 21:01:26 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_err_msg(char *msg)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	g_data.exit_s = 1;
	return (1);
}

int	ft_env(char **args)
{
	t_env	*list;

	list = g_data.envlst;
	if (args && args[1])
		return (env_err_msg(args[1]));
	while (list)
	{
		if (list->value != NULL)
			printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
	return (0);
}
