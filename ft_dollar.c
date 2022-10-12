#include "minishell.h"

int ft_check_nail(char *s)//return(1) -> PATH veya $? çalışıcak demektir return(0)->string olarak algılayacak demektir.
{
    int i;
    int mod;

    i = 0;
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

void    ft_quesmark(void)//$? yazdırma.!!!!!!!!!!!!!!!!!!
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (g_reach->data->new_temp[i])
        i++;
    while(g_reach->data->quesmark[j])
        g_reach->data->new_temp[i++] = g_reach->data->quesmark[j++];
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

void    ft_dollar(char *s, int marked)//PATH yolunu yazma, $? yazma.
{
    int     i;
    int     j;
    char    *p;

    i = marked + 1;
    j = 0;
    p = malloc(20000);
    if (ft_check_nail(s) != 1)
    {
        if (s[i] == '?')//$? için
        {
            ft_quesmark();
            free(p);
            return ;
        }
        while (s[i] && s[i] != 34 && s[i] != ' ')
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
    free(p);
}

void	ft_check_dollar(char *s)//dolar var mı? varsa fonklara yonlendir.
{
	int	i;
    int j;

	i = 0;
    j = 0;
    g_reach->data->new_temp = malloc(2000);
    g_reach->data->new_temp[0] = '\0';
	while (s[i])
	{
		if (s[i] == '$')
        {
            ft_dollar(s, i);
            while (s[i] && s[i] != 34 && s[i] != 39 && s[i] != ' ')
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
}