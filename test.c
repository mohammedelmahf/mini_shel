#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Mock strdup if needed
char *ft_strdup(const char *s)
{
	char *copy;
	size_t i = 0;
	while (s[i]) i++;
	copy = malloc(i + 1);
	if (!copy) return NULL;
	for (size_t j = 0; j <= i; j++)
		copy[j] = s[j];
	return copy;
}

// Mock strcmp
int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (unsigned char)(*s1) - (unsigned char)(*s2);
}

// Garbage collector stub (no-op for now)
void *ft_garbage_collector(void *ptr, bool clean)
{
	(void)clean;
	return ptr;
}

// ---- Environment list functions ----

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_minishell
{
	t_env *envlst;
}	t_minishell;

t_minishell g_minishell = {NULL};

t_env *ft_envlst_new(char *key, char *value)
{
	t_env *node = malloc(sizeof(t_env));
	if (!node)
		return NULL;
	node->key = ft_garbage_collector(ft_strdup(key), false);
	node->value = ft_garbage_collector(ft_strdup(value), false);
	node->next = NULL;
	return node;
}

void ft_envlst_back(t_env *node)
{
	t_env *curr = g_minishell.envlst;
	if (!curr)
	{
		g_minishell.envlst = node;
		return;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = node;
}

// 🧪 The function you gave me
void	ft_update_envlst(char *key, char *value, bool create)
{
	t_env	*envlst;

	envlst = g_minishell.envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
		{
            printf("key--->%s\n" ,key);
			if (value)
				envlst->value = ft_garbage_collector(ft_strdup(value), false);
			return ;
		}
		envlst = envlst->next;
	}
	if (create)
		ft_envlst_back(ft_envlst_new(key, value));
}

// 🖨️ Helper to print env list
void print_envlst(void)
{
	t_env *curr = g_minishell.envlst;
	printf("Current environment list:\n");
	while (curr)
	{
		printf("  %s=%s\n", curr->key, curr->value);
		curr = curr->next;
	}
	printf("\n");
}

// 🧪 Main test
int main(void)
{
	ft_update_envlst("USER", "mohammed", true);
	ft_update_envlst("HOME", "/home/momo", true);
	ft_update_envlst("SHELL", "/bin/bash", true);
	print_envlst();

	// Test updating existing key
	ft_update_envlst("USER", "elmahfoudi", true);
	print_envlst();

	// Test creating new one with create=false (won't add)
	ft_update_envlst("NEWVARu", "something", true);
	print_envlst();

	// Test creating new one with create=true (will add)
	ft_update_envlst("NEWVAR", "something", true);
	print_envlst();

	return 0;
}
