#include "../../includes/minishell.h"

long	ft_atoi(const char *str)
{
	long	r;
	int		i;
	int		s;

	i = 0;
	s = 1;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		if (r > LONG_MAX)
			return (0);
		i++;
	}
	return (r * s);
}