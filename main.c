#include "minishell.h"

int	ft_control_builtin(void)
{
	if (ft_strncmp(g_reach->data->arg[0], "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(g_reach->data->arg[0], "export", 6) == 0)
		return (1);
	else if (ft_strncmp(g_reach->data->arg[0], "env", 3) == 0)
		return (1);
	else if (ft_strncmp(g_reach->data->arg[0], "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(g_reach->data->arg[0], "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(g_reach->data->arg[0], "cd", 2) == 0)
		return (1);
	return (0);
}

void	ft_commands(void)
{
	if (ft_strncmp(g_reach->data->arg[0], "pwd", 3) == 0)
		ft_putendl_fd(getcwd(g_reach->data->cwd, sizeof(char *)), 1);
	else if (ft_strncmp(g_reach->data->arg[0], "echo", 4) == 0)
		ft_echo(g_reach->data->arg);
	else if (ft_strncmp(g_reach->data->arg[0], "cd", 2) == 0)
		ft_cd(g_reach->data->arg);
	else if (ft_strncmp(g_reach->data->arg[0], "export", 6) == 0)
		g_reach->data->export = ft_export(g_reach->data->export, g_reach->data->arg);
	else if (ft_strncmp(g_reach->data->arg[0], "env", 3) == 0)
		ft_env(g_reach->data->env_in);
	else if (ft_strncmp(g_reach->data->arg[0], "unset", 5) == 0)
		ft_unset(g_reach->data->export, g_reach->data->arg);//düzenle.
	else if (access(ft_strjoin("/bin/", g_reach->data->arg[0]), X_OK) != -1)
		execve(ft_strjoin("/bin/", g_reach->data->arg[0]), g_reach->data->arg, g_reach->data->env_in);
	else if (ft_strncmp(g_reach->data->arg[0], "exit", 4) != 0)
		printf("command not found: %s\n", g_reach->data->arg[0]);
}

int	main(int ac, char **av, char **env)
{
	pid_t	pid;

	(void)ac;
	(void)av;
	g_reach = malloc(sizeof(t_data));
	g_reach->data = malloc(sizeof(t_data));
	ft_copy_env(env);
	ft_copy_export(env);// env'leri kopya olarak kullanıyoruz!
	while (1)
	{

		g_reach->data->temp = readline("$Bismillah\033[0;32mterm\033[0m > ");

		g_reach->data->arg = ft_split(g_reach->data->temp, ' ');
		add_history(g_reach->data->temp);
		if (!g_reach->data->arg)
			continue ;
		if (ft_control_builtin())
			ft_commands();//eger builtinse ve pipe yoksa -> commandsi calistirip continue
		else
		{
			pid = fork();
			if (pid > 0)
				wait(NULL);
			if (pid == 0)//exit ve cd
			{
				ft_commands();
				exit(0);//?
			}
			if (ft_strncmp(g_reach->data->arg[0], "exit", 4) == 0)
			{
				//system("leaks minishell");
				printf("exit\n");
				exit(0);
			}
		}
		//free(g_reach->data->temp);
	}
}
