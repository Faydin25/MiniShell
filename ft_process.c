#include "minishell.h"

int    ft_check(char *arg)
{
    int i;

    i = 0;
    while (arg[i] && (arg[i] == ' ' || arg[i] == '\t'))
        i++;
    return (i);
}

char    *ft_process(char *arg)
{
    char    *s;
    int     j;
    int     i;

    i = 0;
    s = (char *)malloc(sizeof(ft_strlen(arg) + 1));
    j = ft_check(arg);
    while (arg[j])
    {
        while (arg[j] && (arg[j] == ' ' || arg[j] == '\t') && arg[j + 1] && \
            (arg[j + 1] == ' ' || arg[j + 1] == '\t'))
                j++;
        if (arg[j] && arg[j] == '\t')
            arg[j] = ' ';
        s[i++] = arg[j++];
    }
    return (s);
}