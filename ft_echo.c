#include "minishell.h"

static int  ft_check_echo(char *s, char c)
{
    int i;

    i = 0;
    if (s[i] != '-')
        return (1);
    while (s[++i] != '\0')
        if (s[i] != c)
            return (1);
    return (0);
}

void    ft_echo(char **arg)
{
    int i;
    int tmp;

    if (!arg)
    {
        printf("\n");
        return ;
    }
    tmp = ft_check_echo(arg[1], 'n');
    i = (tmp == 0) + 1;
    while (arg[i])
    {
        if (arg[i + 1])
            printf("%s ", arg[i++]);
        else
            printf("%s", arg[i++]);
    }
    if (tmp)
        printf("\n");
}
