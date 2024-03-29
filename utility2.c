/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlcatraZ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:21:35 by AlcatraZ          #+#    #+#             */
/*   Updated: 2023/02/01 20:21:37 by AlcatraZ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	a;

	a = 0;
	while (a < len)
	{
		((unsigned char *)b)[a] = (unsigned char)c;
		a++;
	}
	return (b);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s1);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (0);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	**duplicate_env(char **env)
{
	int		i;
	char	**temp;

	i = 0;
	while (env && env[i])
		i++;
	temp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		temp[i] = ft_strdup(env[i]);
		i++;
	}
	temp[i] = env[i];
	return (temp);
}

void	free_2d_char(char **arr)
{
	int	i;

	if (arr != NULL)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			++i;
		}
		free(arr[i]);
		free(arr);
	}
}
