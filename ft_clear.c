#include "minishell.h"
/*
void    ft_two_pointer(char **s)
{
    int i;

    i = 0;
    while (s[i])
    {
        free(s[i]);
        i++;
    }
    free(s);
}

void    ft_clear(void)
{
    if (g_reach->data->cwd)
        free(g_reach->data->cwd);
    if (g_reach->data->temp)
        free(g_reach->data->temp);
    if (g_reach->data->quesmark)
        free(g_reach->data->quesmark);
    if (g_reach->data->new_temp)
        free(g_reach->data->new_temp);
    if (g_reach->data->export)
        ft_two_pointer(g_reach->data->export);
    if (g_reach->data->env_in)
        ft_two_pointer(g_reach->data->env_in);
    if (g_reach->data->arg)
        ft_two_pointer(g_reach->data->arg);//kullanmıyoruz suan.
    if (g_reach->parse_data->commands)
        ft_two_pointer(g_reach->parse_data->commands);
    if (g_reach->parse_data->flags)
        ft_two_pointer(g_reach->parse_data->flags);
    if (g_reach->parse_data->redirections)
        ft_two_pointer(g_reach->parse_data->redirections);
    if (g_reach->code->commands)
        free(g_reach->code->commands);
    if (g_reach->code->flags)
        free(g_reach->code->flags);
    if (g_reach->code->redirections)
        free(g_reach->code->redirections);
    free(g_reach->code);
    free(g_reach->data);
    free(g_reach->parse_data);
    free(g_reach);
}*/