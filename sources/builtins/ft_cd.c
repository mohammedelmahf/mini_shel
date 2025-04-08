#include"../includes/minishell.h"

int ft_cd(char *path)
{
    char * home ;
    //char *oldpwd;
    
    if(!path)
    {
        home  = getenv("HOME");
        if(!home)
        {
            //strr ??!! att bb !!
            printf("minishell: cd: HOME not set\n");
        }
        path = home;
    }
    if(chdir(path) == - 1)
    {
        perror("minishell: cd")
        return 1;
    }
    return 0;
}