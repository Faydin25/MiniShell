#include "minishell.h"

int ft_check_nail(char *s, int marked)//return(1) -> PATH veya $? çalışıcak demektir return(0)->string olarak algılayacak demektir.
{
    int i;
    int mod;

    i = marked - 1;
    mod = 0;//mod=0->tırnak yok //mod=1->tek tırnak //mod=2 çift tırnak.
    while (s[i] && s[i] != '$')
    {
        if (s[i] == 34 && (mod == 0 || mod == 2))
        {
            if (mod == 0)
                mod = 2;
            else
                mod = 0;
        }
        else if (s[i] == 39 && (mod == 0 || mod == 1))
        {
            if (mod == 0)
                mod = 1;
            else
                mod = 0;
        }
        i++;
    }
    return (mod);
}

void    ft_until_dollar(char *s, int marked)//$ görene kadar yazdık.
{
    int     i;

    i = 0;
    while (i < marked)
    {
       g_reach->data->new_temp[i] = s[i];
        i++;
    }
    g_reach->data->new_temp[i] = '\0';
}

void    ft_quesmark(char *s, int marked)//$? yazdırma.
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (g_reach->data->new_temp[i])
        i++;
    while(g_reach->data->quesmark[j])
        g_reach->data->new_temp[i++] = g_reach->data->quesmark[j++];
    j = marked + 1;
    while (s[j] && s[j] != 34 && s[j] != 39 && s[j] != ' ' && s[j] != '$')
        g_reach->data->new_temp[i++] = s[j++];
    g_reach->data->new_temp[i] = '\0';
}

void    ft_combine(char *s)//$... yazdırma.
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (g_reach->data->new_temp[i])
        i++;
    while (s[j] && s[j] != '=')
        j++;
    if (s[j])
        j++;
    while (s[j])
        g_reach->data->new_temp[i++] = s[j++];
    g_reach->data->new_temp[i] = '\0';
    
}

void    ft_write_to_new_temp(char *s, int marked)
{
    int i;
    int j;

    i = marked;
    j = 0;
    while (g_reach->data->new_temp[j])
        j++;
    g_reach->data->new_temp[j] = s[marked - 1];
    g_reach->data->new_temp[++j] = '\0';
    (void)s;
    while (s[i] && s[i] != ' ' && s[i] != '$' && s[i] != 34 && s[i] != 39)
    {
        j = 0;
        while (g_reach->data->new_temp[j])
            j++;
        g_reach->data->new_temp[j++] = s[i++];
        g_reach->data->new_temp[j] = '\0';
    }
    g_reach->data->new_temp[j] = '\0';
}

void    ft_dollar(char *s, int marked)//PATH yolunu yazma, $? yazma.
{
    int     i;
    int     j;
    char    *p;

    if (s[marked + 1])
        i = marked + 1;
    else 
        return ;

    j = 0;
    p = malloc(20000);
    if (ft_check_nail(s, marked) != 1)
    {
        if (s[i] == '?')//$? için
        {
            ft_quesmark(s, i);
            free(p);
            return ;
        }
        while (s[i] && s[i] != 34 && s[i] != ' ' && s[i] != '$')
        {
            p[j++] = s[i++];
        }
        p[j] = '\0';
        i = -1;
        while (g_reach->data->env_in[++i])
        {
            if (ft_strncmp(g_reach->data->env_in[i], p, j) == 0)
                ft_combine(g_reach->data->env_in[i]);
        }
    }
    else
        ft_write_to_new_temp(s, i);
    free(p);
}

void	ft_check_dollar(char *s)//dolar var mı? varsa fonklara yonlendir.
{
	int	i;
    int j;

	i = 0;
    j = 0;
    g_reach->data->new_temp = malloc(20000);
    g_reach->data->new_temp[0] = '\0';
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] != '\0')
        {
            ft_dollar(s, i);
                i++;
            while (s[i] && s[i] != 34 && s[i] != 39 && s[i] != ' ' && s[i] != '$')
                i++;
        }
        else
        {
            while (g_reach->data->new_temp[j])
                j++;
            g_reach->data->new_temp[j++] = s[i++];
            g_reach->data->new_temp[j] = '\0';
        }
	}
    printf("%s\n", g_reach->data->new_temp);
}