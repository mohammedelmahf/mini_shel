/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:15 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/16 09:11:50 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	bool	is_valid_long_long(const char *str)
{
	int			i = 0;
	int			sign = 1;
	unsigned long long	num = 0;
	unsigned long long	max = (unsigned long long)LLONG_MAX + 1;

	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	if (!str[i])
		return (false);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > LLONG_MAX) || (sign == -1 && num > max))
			return (false);
		i++;
	}
	return (true);
}

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
	unsigned char	exit_code;

	exit_code = g_data.exit_s;
	printf("exit\n");
	if (s[1])
	{
		if (!is_valid_long_long(s[1]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(s[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			clean_all();
			exit(2);
		}
		if (s[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			g_data.exit_s = 1;
			return (1);
		}
		exit_code = (unsigned char)ft_atoi(s[1]);
	}
	(clean_all(), exit(exit_code));
	return (0);
}
