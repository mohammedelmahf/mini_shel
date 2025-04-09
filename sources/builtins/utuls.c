#include "../../includes/minishell.h"

char	*ft_getenv(const char *name)
{
	t_env	*tmp;

	if (!name)
		return (NULL);
	tmp = data.envlst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, name))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 		{
// 			return ((char *)&s[i]);
// 		}
// 		i++;
// 	}
// 	if (c == '\0')
// 	{
// 		return ((char *)&s[i]);
// 	}
// 	return (NULL);
// }

