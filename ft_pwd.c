#include "minishell.h"

void    ft_pwd(char **arg)
{
    ft_putendl_fd(getcwd(g_reach->data->cwd, sizeof(char *)), 1);
    g_reach->data->quesmark = "0";
}