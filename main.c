#include "minishell.h"

void	ft_signalhandler(int sig)//
{
	(void)sig;
	g_reach->data->quesmark = "1";
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	control_D(void)
{
	printf("exit\n");
	exit(0);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_signalhandler);
	g_reach = malloc(sizeof(t_reach));
	g_reach->data = malloc(sizeof(t_data));
	ft_copy_export(env);
	g_reach->data->new_temp = NULL;
	while (1)
	{
		g_reach->data->temp = readline("$Bismillah\033[0;32mterm\033[0m > ");
		if (!g_reach->data->temp)
			control_D();
		add_history(g_reach->data->temp);
		g_reach->data->temp = ft_process(g_reach->data->temp);
		ft_check_dollar(g_reach->data->temp);
		//ft_parser(ac, g_reach->data->new_temp);
		//ft_routine(ac, av, env);
	}
	return (0);
}
