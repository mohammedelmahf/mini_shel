#include "../../includes/minishell.h"

int	ft_cd(char **args)
{
	char	*oldpwd;
	char	*cwd;

	if (!args[1])
	{
		ft_putstr_fd("minishell: cd: path required\n", 2);
		return (1);
	}

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
	{
		perror("minishell: cd (getcwd)");
		return (1);
	}

	if (chdir(args[1]) == -1)
	{
		perror("minishell: cd");
		free(oldpwd);
		return (1);
	}
	update_envlst("OLDPWD", oldpwd, true);
	free(oldpwd);

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		update_envlst("PWD", cwd, true);
		free(cwd);
	}
	else
		perror("minishell: cd (getcwd)");

	return (0);
}
