#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0 && s)
		write(fd, s, ft_strlen(s));
}

bool    usage_message(bool return_valu)
{
    ft_putstr_fd("Usage: ./minishell\n" , 2);
    ft_putstr_fd("Usage: ./minishell -c \"input line\"\n", 2);
    return (return_valu);
}

int main()
{
    bool done = usage_message(true);
    if (done)
    {
        printf("Ready to go!\n");
    } else
    {
        printf("Not ready.\n");
    }
}