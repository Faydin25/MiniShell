/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:12:56 by faydin            #+#    #+#             */
/*   Updated: 2022/01/29 23:19:53 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcounter(const char *s, char c)//
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (i);
		while (*s != c && *s)
			s++;
		i++;
	}
	return (i);
}

static	int	charcounter(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && (*s != c))
	{
		i++;
		s++;
	}
	return (i);
}

void	*ft_space_cntrl(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return ((void *)1);
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		retindex;

	if (!s || !*s)
		return (0);
	if (!ft_space_cntrl(s, c))
		return (NULL);
	ret = NULL;
	retindex = 0;
	ret = malloc(sizeof(char *) * wordcounter(s, c) + 1);
	if (!ret)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		ret[retindex] = ft_substr(s, 0, charcounter(s, c));
		retindex++;
		s = s + charcounter(s, c);
	}
	ret[retindex] = NULL;
	return (ret);
}
