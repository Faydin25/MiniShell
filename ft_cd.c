#include "minishell.h"

void	ft_cd_second(char *arg)//
{
		if (chdir(arg) != 0)
			perror(arg);
		g_reach->data->quesmark = "0";
}

void	ft_cd(char **arg)
{
	char	*s;
	int		i;

	s = 0;
	i = 0;
	while (arg[i])
		i++;
	if (i > 2)
	{
		printf("To many args!\n");
		return ;
	}
	if (!arg[1] || ft_strchr(arg[1], '~'))
	{
		while (g_reach->data->export[++i])
		{
			if (ft_strncmp(g_reach->data->export[i], "HOME", 4) == 0)
			{
				s = ft_strdup(g_reach->data->export[i]);
				break;
			}
		}
	}
	if (!arg[1])
	{
		if (chdir(ft_strchr(s, '=') + 1))
			perror(arg[0]);
		free(s);
		g_reach->data->quesmark = "0";
	}
	else if (arg[1] && arg[1][0] == '~' && arg[1][1] == '/')
		ft_cd_second(ft_strjoin(ft_strchr(s, '=') + 1, arg[1] + 1));
	else if (arg[1])
	{
		if (chdir(arg[1]))
				perror(arg[1]);
		g_reach->data->quesmark = "0";
	}
}