#include "minishell.h"

void    ft_one_pointer(char *s)
{
    free(s);
}

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
    ft_one_pointer(g_reach->data->cwd);
    ft_one_pointer(g_reach->data->temp);
    ft_one_pointer(g_reach->data->quesmark);
    ft_one_pointer(g_reach->data->new_temp);
    ft_two_pointer(g_reach->data->export);
    ft_two_pointer(g_reach->data->env_in);
    //ft_two_pointer(g_reach->data->arg);//kullanmıyoruz suan.
    /*ft_two_pointer(g_reach->parse_data->commands);
    ft_two_pointer(g_reach->parse_data->flags);
    ft_two_pointer(g_reach->parse_data->redirections);
    ft_one_pointer(g_reach->code->commands);
    ft_one_pointer(g_reach->code->flags);
    ft_one_pointer(g_reach->code->redirections);
    free(g_reach->code);
    free(g_reach->data);
    free(g_reach->parse_data);
    free(g_reach);*/
}