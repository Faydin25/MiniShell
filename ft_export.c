#include "minishell.h"

void    ft_just_export(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        printf("declare -x %s\n", env[i]);
        i++;
    }
}

char    **ft_add_malloc_for_env(char **env)
{
    int i;
    char **new;

    i = 0;
    while(env[i])
        i++;
    new =  (char **)malloc(sizeof(char *) * (++i + 1));
    i = 0;
    while (env[i])
    {
        new[i] = env[i];
        i++;
    }
    new[i + 1] = 0;
    free(env);
    return (new);
}

void    ft_go_env(char *export)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (export[i] && export[i] != '=')
        i++;
    while (g_reach->data->env_in[j] &&ft_strncmp(g_reach->data->env_in[j], export, i - 1) != 0)
        j++;
    i = 0;
    while (export[i])
        i++;
    free(g_reach->data->env_in[j]);
    g_reach->data->env_in[j] = (char *)malloc(sizeof(i + 1));
    ft_memcpy(g_reach->data->env_in[j], export, i);
    g_reach->data->env_in[j][++i] = '\0';
}

int ft_check_export2(char *arg)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (arg[j] && arg[j] != '=')
        j++;
    while (g_reach->data->export[i])
    {
        if ((ft_strncmp(g_reach->data->export[i], arg, j - 1)) != 0)
            i++;
        else
        {
            if (arg[j] == '=')
            {
                j = 0;
                while (arg[j])
                    j++;
                g_reach->data->export[i] = (char *)malloc(sizeof (j));
                ft_memcpy(g_reach->data->export[i], arg, j);
                ft_go_env(g_reach->data->export[i]);
                return (1);
            }
        }
    }
    return (0);
}

int ft_check_export(char *arg)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z')))
        return (1);
    while (arg[j])
    {
        if (arg[j] == '=')
            return (0);
        j++;
    }
    while (g_reach->data->export[i])
    {
        if (ft_strncmp(g_reach->data->export[i], arg, j - 1) != 0)
            i++;
        else
        {
            return (2);
        }
    }
    return (0);
}

char    **ft_export(char **env, char **arg)
{
    int i;
    int j;
    int k;

    if (!arg[1])
        ft_just_export(g_reach->data->export);
    else
    {
        k = 0;
        while (arg[++k])
        {
            if (ft_check_export(arg[k]))
            {
                i = ft_check_export(arg[k]);
                if (i != 2)
                {
                    printf("export: '%s': not a valid identifier\n", arg[k]);
                    continue ;
                }
            }
            if (ft_check_export2(arg[k]))
                continue ;
            i = 0;
            j = 0;
            while (env[i])
                i++;
            while(arg[k][j])
                j++;
            env = ft_add_malloc_for_env(env);
            env[i] = (char *)malloc(sizeof(char) * (j + 1));
            env[i][j] = '\0';
            ft_strncpy(env[i], arg[k], j);
            ++arg;
            if (!arg)
                break ;
        }
        ft_for_env(env[i]);
    }
    return (env);
}