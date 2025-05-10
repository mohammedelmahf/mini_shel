/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:15 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/10 12:21:18 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (false);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_exit(char **s)
{
	if (s[1])
	{
		if (!ft_isnumber(s[1]))
		{
			printf("exit\n");
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(s[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(2);
		}
		if (s[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			g_data.exit_s = 1;
			return (1);
		}
		printf("exit\n");
		exit((unsigned char)ft_atoi(s[1]));
	}

	printf("exit\n");
	exit(g_data.exit_s);
}