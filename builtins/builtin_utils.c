/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlcatraZ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:26:19 by AlcatraZ          #+#    #+#             */
/*   Updated: 2023/02/01 20:26:20 by AlcatraZ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_builtin(char *s1, char *s2)
{
	char	*last;
	int		b;

	b = ft_strlen(s1);
	last = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!last)
		return (0);
	ft_strlcpy(last, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&last[b], s2, ft_strlen(s2) + 1);
	free(s1);
	return (last);
}

int	ft_strncmp_builtin(char *s1, char *s2, int a)
{
	int	i;

	i = 0;
	while (i < a && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '=' || s1[i] == '\0')
	{
		return (1);
	}
	return (0);
}

char	*ft_strjoin_env(char *s1, char *s2)
{
	char	*last;
	int		b;

	b = ft_strlen(s1);
	last = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!last)
		return (0);
	ft_strlcpy(last, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&last[b], s2, ft_strlen(s2) + 1);
	free(s2);
	return (last);
}

char	*ft_strdup_env(char *s1)
{
	char	*s;
	int		len;
	int		i;
	int		a;

	i = 0;
	a = 5;
	len = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * len - 4);
	if (!s)
		return (0);
	while (s1[a] != '\0')
	{
		s[i] = s1[a];
		i++;
		a++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_strncmp_export(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (s1[0] == '\0' || s2[0] == '\0')
		return (0);
	while (i < size && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' || s1[i] == '=')
	{
		return (1);
	}
	return (0);
}
