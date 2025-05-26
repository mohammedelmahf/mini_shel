/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:15 by iel-asef          #+#    #+#             */
/*   Updated: 2025/05/26 09:28:59 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	check_sign(const char *str, int *sign, int *index)
{
	*sign = 1;
	*index = 0;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			*sign = -1;
		(*index)++;
	}
	if (!str[*index])
		return (false);
	return (true);
}

static bool	is_valid_long_long(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	num;
	unsigned long long	max;

	if (!check_sign(str, &sign, &i))
		return (false);
	num = 0;
	max = (unsigned long long)LLONG_MAX + 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > (unsigned long long)LLONG_MAX)
			|| (sign == -1 && num > max))
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
