/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlcatraZ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:24:43 by AlcatraZ          #+#    #+#             */
/*   Updated: 2023/02/01 20:24:44 by AlcatraZ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer_ft_strlen(char *s1)
{
	int	a;

	a = 0;
	while (s1[a] != '\0')
		a++;
	return (a);
}

char	*lexer_ft_strjoin(char *s1, char *s2)
{
	int		a;
	char	*last;
	int		b;

	a = 0;
	b = lexer_ft_strlen(s1);
	last = malloc(sizeof(char) * \
		(lexer_ft_strlen(s1) + lexer_ft_strlen(s2) + 1));
	if (!last)
		return (0);
	while (b > a)
	{
		last[a] = s1[a];
		a++;
	}
	a = 0;
	while (lexer_ft_strlen(s1) + lexer_ft_strlen(s2) > a)
	{
		last[b + a] = s2[a];
		a++;
	}
	free(s1);
	free(s2);
	return (last);
}

int	lexer_escapespace(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	if (((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && argv[i] != '\0')
	{
		while (((argv[i] <= 13 && argv[i] >= 9)
				|| argv[i] == 32) && argv[i] != '\0')
			i++;
		if (tolex->box2index != 0)
			tolex->box2[tolex->box2index++] = 32;
		tolex->box2lastisspace = 1;
	}
	return (i);
}

int	box4escapespace(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	while (((argv[i] <= 13 && argv[i] >= 9) || \
		argv[i] == 32) && argv[i] != '\0')
	{
		i++;
		tolex->box4space = 1;
	}
	return (i);
}
