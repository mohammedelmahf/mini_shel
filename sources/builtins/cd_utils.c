#include  "../../includes/minishell.h"

char *ft_getenv(char *key)
{
    t_env *env = data.envlst;

    while (env)
    {
        if (!ft_strcmp(env->key, key))
            return (env->value);
        env = env->next;
    }
    return (NULL);
}