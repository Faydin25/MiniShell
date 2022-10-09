#include "minishell.h"

void    ft_env(char **env_in)// env yanına arguman almamalı.kontrolunun mainde yapılması daha mantıklı.
{
    int i;

    i = 0;
    while (env_in[i])
    {
        printf("%s\n", env_in[i++]);
    }
    g_reach->data->quesmark = "0";
}