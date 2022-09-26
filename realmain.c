#include "minishell.h"

int	main(int ac, char **av, char **env)
{
    g_reach->data = malloc(sizeof(t_data));
    ft_copy_env(env);
    while (1)
    {
        g_reach->data->temp = readline("$Bismillah\033[0;32mterm\033[0m > ");
        add_history(g_reach->data->temp);
        ft_parser(ac, av);//Tarık
        ft_routine(ac, av, env);//Zehra
    }
    //sysyem("leaks minishell");
    return (0);
}