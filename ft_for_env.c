#include "minishell.h"

char    **ft_go_malloc(void)
{
    int i;
    int j;
    char **new;

    i = 0;
    j = 0;
    while(g_reach->data->env_in[i])
        i++;
    new =  (char **)malloc(sizeof(char *) * (++i + 1));
    i = 0;
    while (g_reach->data->env_in[j])
    {
        new[j] = g_reach->data->env_in[j];
        j++;
    }
    i = 0;
    while (g_reach->data->env_in[i])
        i++;
    new[j + 1] = 0;
    free(g_reach->data->env_in);
    return (new);
}

void    ft_write_env(char *ex)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    g_reach->data->env_in = ft_go_malloc();
    while (g_reach->data->env_in[j])
        j++;
    while (ex[i])
        i++;
    g_reach->data->env_in[j] = (char *)malloc(sizeof(i + 1));
    g_reach->data->env_in[j][i + 1] = '\0';
    i = 0;
    while (ex[i])
    {
        g_reach->data->env_in[j][i] = ex[i];
        i++;
    }
}

void    ft_for_env(char *ex)
{
     int    i;

     i = 0;
     while (ex[i])
     {
         if (ex[i] == '=')
            {
                ft_write_env(ex);
                break ;
            }
         i++;
     }
}