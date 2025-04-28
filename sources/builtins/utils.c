#include "../../includes/minishell.h"

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
