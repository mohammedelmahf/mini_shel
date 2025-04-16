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

t_env *get_env(char *key)
{
	t_env *tmp;

	tmp = data.envlst;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
