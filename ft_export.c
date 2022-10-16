#include "minishell.h"

void    ft_just_export(char **env)
{
    int i;

    i = 0;
    while (env[i])
            printf("declare -x %s\n", env[i++]);
}

int ft_check_arg_sup(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '=')
            return (i);
        i++;
    }
    return (0);
}

int ft_check_arg(char *s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i])
        i++;
    while (g_reach->data->export[j])
    {
        if (ft_strncmp(g_reach->data->export[j], s, i) == 0)
            return (1);
        j++;
    }
    return (0);
}

int ft_check_arg2(char *s)
{
    int i;
    int j;

    j = -1;
    if (ft_check_arg_sup(s))
    {
        i = ft_check_arg_sup(s);
        while (g_reach->data->export[++j])
        {
            if (ft_strncmp(g_reach->data->export[j], s, i) == 0)
                return (1);
        }
    }
    return (0);
}

void    ft_go_change(char **env, char *arg)
{
    int i;
    int j;

    i = 0;
    j = -1;
    while (arg[i] && arg[i] != '=')
        i++;
    while (env[++j])
    {
        if (ft_strncmp(env[j], arg, i) == 0)
            break ;
    }
    i = 0;
    while (arg[i])
        i++;
    free(g_reach->data->export[j]);
    g_reach->data->export[j] = (char *)malloc(sizeof (i + 1));
    i = -1;
    while (arg[++i])
        g_reach->data->export[j][i] = arg[i];
}

char    **ft_add_malloc_for_env(char **env)
{
    int i;
    char **new;

    i = 0;
    while(env[i])
        i++;
    new = (char **)malloc(sizeof(char *) * (++i + 1));
    i = 0;
    while (env[i])
    {
        new[i] = env[i];
        i++;
    }
    new[i] = 0;
    new[i + 1] = 0;
    i = 0;
    free(g_reach->data->export);
    return (new);
}

void    ft_go_write(char *s)
{
    int i;
    int j;

    j = 0;
    i = 0;
    g_reach->data->export = ft_add_malloc_for_env(g_reach->data->export);
    while (g_reach->data->export[j])
        j++;
    while (s[i])
        i++;
    g_reach->data->export[j] = (char *)malloc(sizeof(i));
    i = 0;
    while (s[i])
    {
        g_reach->data->export[j][i] = s[i];
        i++;
    }
    g_reach->data->export[j][i] = '\0';
    g_reach->data->export[++j] = 0;
}

void    ft_export(char **env, char **arg)
{
    int i;
    int j;

    i = 0;
    j = 1;
    if (!arg[j])
        ft_just_export(env);
    else
    {
        while (arg[j])
        {
            if (ft_check_arg(arg[j]))
            {
                j++;
                continue ;
            }
            if (ft_check_arg2(arg[j]))
                ft_go_change(g_reach->data->export, arg[j]);
            else
                ft_go_write(arg[j]);
            free(arg[j]);
            j++;
        }
    }
}