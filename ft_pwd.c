#include "minishell.h"

void    ft_pwd(char **arg)
{
	char *pwd = getcwd(g_reach->data->cwd, sizeof(char *));
    ft_putendl_fd(pwd, 1);
	free(pwd);
    g_reach->data->quesmark = "0";
}