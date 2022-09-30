#include "minishell.h"

void	ft_cd_second(char *arg)
{
		if (chdir(arg) != 0)
			perror(arg);
}

void	ft_cd(char **arg)
{
	char	*s;
	int		i;

	s = 0;
	i = 0;
	if (!arg[1] || ft_strchr(arg[1], '~'))
	{
		while (g_reach->data->env_in[++i])
		{
			if (ft_strncmp(g_reach->data->env_in[i], "HOME", 4) == 0)
			{
				s = ft_strdup(g_reach->data->env_in[i]);
				break;
			}
		}
	}
	if (!arg[1])
	{
		if (chdir(ft_strchr(s, '=') + 1))
			perror(arg[0]);
		free(s);
	}
	else if (arg[1] && arg[1][0] == '~' && arg[1][1] == '/')
		ft_cd_second(ft_strjoin(ft_strchr(s, '=') + 1, arg[1] + 1));
	else if (arg[1])
	{
		if (chdir(arg[1]))
				perror(arg[1]);
	}
}