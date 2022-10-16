#include "minishell.h"

void ft_malloc_for_export(char **env)
{
    int i;
    int j;

    j = 0;
    while (env[j])
        j++;
    g_reach->data->export = (char **)malloc(sizeof(char *) * (j));
    j = 0;
    while(env[j])
    {
        i = 0;
        while (env[j][i])
            i++;
        g_reach->data->export[j] = (char *)malloc(sizeof(char) * (i + 1));
        g_reach->data->export[j][i] = '\0';
        j++;
    }
}

void    ft_copy_export(char **env)
{
    int i;
    int j;

    j = 0;
    ft_malloc_for_export(env);
    while(env[j])
    {
        i = 0;
        while(env[j][i])
        {
            g_reach->data->export[j][i] = env[j][i];
            i++;
        }
        j++;
    }
}