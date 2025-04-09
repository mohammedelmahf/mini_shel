#ifndef BUILTINS_H
#define BUILTINS_H


//pwd.c
int  ft_pwd (void);
//cd.c
int ft_cd(char **arg);
//utils
char	*ft_getenv(const char *name);

//exit

//export 
int parsinge_export(char *str);

//echo 
int	ft_echo(char **str);
int  parsinge_echo(char *str);
#endif