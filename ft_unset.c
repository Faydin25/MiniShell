#include "minishell.h"

int ft_check_arg(char **env, char *arg)
{
    int i;
    int k;
    int j;

    i = 0;
    k = -1;
    j = 0;
    while (arg[j])
        j++;
    while (env[++k])
    {
        if (ft_strncmp(env[k], arg, j) == 0)
            return (k);
    }
    return (0);
}

int    ft_check_equality(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (arg[i] == '=')
            return(1);
        i++;
    }
    return (0);
}

char    **ft_delete_env(char **env, int marked)
{
    int idx;
    int jdx;
    int end;
    char    **new;

 
    idx = 0;
    end = 0;
    while (env[idx])
        idx++;
    new = (char **)malloc(sizeof(char *) * (idx));
    jdx = 0;
    while (jdx < idx - 1)
    {
        if (jdx == marked)
        {
            env++;
            end = 1;
        }
        new[jdx] = env[jdx];
        jdx++;
    }
    new[jdx] = 0;
    env -= end;
    free(env[marked]);
    return (new);
}

void    ft_unset(char **env, char **arg)
{
    int i;
    int k;

    k = 0;
    while (arg[++k])
    {
        if (ft_check_arg(env, arg[k]))
        {
            i = ft_check_arg(env, arg[k]);
            g_reach->data->env_in = ft_delete_env(env, i);
        }
    }
    g_reach->data->quesmark = "0";
}