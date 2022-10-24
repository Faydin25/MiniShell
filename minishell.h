#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./libft/libft.h"
//#include "./parser.h"
//#include "redirection";

typedef struct s_data
{
	char		*temp;
	char		*cwd;
	char		*quesmark;
	char		*new_temp;
	char		**arg;
	char		**export;
}			t_data;

typedef struct s_parser
{
    char    **commands;
    char    **flags;
    char    **redirections;
} 			parse_data;

typedef struct s_code
{
    char    *commands;
	char	*flags;
    char    *redirections;
	int		pipes[2];
	pid_t	pid;
	int		son;
} 			t_code;

typedef	struct s_reach
{
	t_code		*code;
	t_data		*data;
	parse_data	*parse_data;
}	t_reach;

t_reach	*g_reach;

void	ft_echo(char **arg);
void	ft_commands(void);
void	ft_cd(char **arg);
void	ft_routine(void);
void    ft_env(char **env_in);
void	ft_just_export(char **env);
void	ft_export(char **env, char **arg);
char    *ft_process(char *arg);
void	ft_copy_env(char **env);
void	ft_malloc_for_env(char **env);
void	ft_unset(char **arg, char **env);
void ft_malloc_for_export(char **env);
void    ft_copy_export(char **env);
void    ft_new_env(char *export);
void    ft_for_env(char *ex);
void	ft_check_dollar(char *s);
void    ft_clear(void);

#endif
