#include "../../includes/minishell.h"

int	ft_env(void)
{
	t_env	*list;

	list = data.envlst;
	while (list)
	{
		if (list->value != NULL)
			printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
	return (0);
}