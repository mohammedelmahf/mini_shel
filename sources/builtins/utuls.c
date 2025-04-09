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
