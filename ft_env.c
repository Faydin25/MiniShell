#include "minishell.h"

int ft_check_env(char *env)
{
    int i;

    i = 0;
    while (env[i])
    {
        if (env[i] == '=')
            return (1);
        i++;
    }
    return (0);
}

void    ft_env(char **env_in)
{
    int i;

    i = 0;
    while (env_in[i])
    {
        if (ft_check_env(env_in[i]))
        printf("%s\n", env_in[i]);
        i++;
    }
}