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

typedef struct s_data
{
	char		*temp;
	char		**arg;//bütün argümanları burada almam lazım!
	char		**env_in;//bütün envleri burada almam lazım!
	char		**export;
	char		*cwd;
}			t_data;

typedef struct s_data
{
    char    **commands;
    char    **redirections;
    char    **builtins;
} parse_data;

typedef	struct s_reach
{
	t_data		*data;
	parse_data	*parse_data;
}				t_reach;


t_reach	*g_reach;

void	ft_echo(char **arg);
void	ft_commands(void);
void	ft_cd(char **arg);
void	ft_routine(void);
void    ft_env(char **env_in);
void	ft_just_export(char **env);
char	**ft_export(char **env, char **arg);
void	ft_copy_env(char **env);
void	ft_malloc_for_env(char **env);
void	ft_unset(char **env, char **arg);
void ft_malloc_for_export(char **env);
void    ft_copy_export(char **env);

int         check_item_around(char *first_command, int pipe_index, int tirnak);
int         *get_item_index(char *first_command, char c);
char        **ft_split_bypipe(char *cmd);
int         get_int_po_count(int *pipe_indexs);
int         check_null_cmd(char *str, int i);
int         get_matris_count(char **str);
char        **get_builtins(void);
parse_data  *fill_data(char **commands);
char        **get_cmd_redirections(char **commands);
char        *find_red(char *pipeline);
#endif
