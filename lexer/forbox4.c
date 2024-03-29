/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbox4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlcatraZ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:24:23 by AlcatraZ          #+#    #+#             */
/*   Updated: 2023/02/01 20:24:24 by AlcatraZ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	box4greatgreat(char *argv, t_lexout *tolex)
{
	int	i;

	if (tolex->box4space == 1)
		tolex->box4[tolex->box4index++] = 32;
	tolex->box4space = 0;
	i = 0;
	tolex->box4[tolex->box4index++] = argv[i];
	argv[i++] = 32;
	tolex->box4[tolex->box4index++] = argv[i];
	argv[i++] = 32;
	i += box4escapespace(argv + i, tolex);
	while (!((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && \
		argv[i] != '\0' && argv[i] != '<' && argv[i] != '>' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += box4inquote_mode2(argv + i, tolex);
		else if (argv[i] == 39)
			i += box4insinglequote_mode2(argv + i, tolex);
		else
		{
			tolex->box4[tolex->box4index++] = argv[i];
			argv[i++] = 32;
		}
	}
	return (i);
}

int	box4great(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	if (tolex->box4space == 1)
	{
		tolex->box4[tolex->box4index++] = 32;
		tolex->box4space = 0;
	}
	tolex->box4[tolex->box4index++] = argv[i];
	argv[i++] = 32;
	i += box4escapespace(argv + i, tolex);
	while (!((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && \
		argv[i] != '\0' && argv[i] != '<' && argv[i] != '>' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += box4inquote_mode2(argv + i, tolex);
		else if (argv[i] == 39)
			i += box4insinglequote_mode2(argv + i, tolex);
		else
		{
			tolex->box4[tolex->box4index++] = argv[i];
			argv[i++] = 32;
		}
	}
	return (i);
}

int	box4lessless(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	if (tolex->box4space == 1)
		tolex->box4[tolex->box4index++] = 32;
	tolex->box4space = 0;
	tolex->box4[tolex->box4index++] = argv[i];
	argv[i++] = 32;
	tolex->box4[tolex->box4index++] = argv[i];
	argv[i++] = 32;
	i += box4escapespace(argv + i, tolex);
	while (!((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && \
		argv[i] != '\0' && argv[i] != '<' && argv[i] != '>' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += box4inquote_mode2(argv + i, tolex);
		else if (argv[i] == 39)
			i += box4insinglequote_mode2(argv + i, tolex);
		else
		{
			tolex->box4[tolex->box4index++] = argv[i];
			argv[i++] = 32;
		}
	}
	return (i);
}

int	box4less(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	if (tolex->box4space == 1)
	{
		tolex->box4[tolex->box4index++] = 32;
		tolex->box4space = 0;
	}
	tolex->box4[tolex->box4index++] = argv[i];
	argv[i++] = 32;
	i += box4escapespace(argv + i, tolex);
	while (!((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && \
		argv[i] != '\0' && argv[i] != '<' && argv[i] != '>' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += box4inquote_mode2(argv + i, tolex);
		else if (argv[i] == 39)
			i += box4insinglequote_mode2(argv + i, tolex);
		else
		{
			tolex->box4[tolex->box4index++] = argv[i];
			argv[i++] = 32;
		}
	}
	return (i);
}

int	box4wtf(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	if (tolex->box4space == 1)
		tolex->box4[tolex->box4index++] = 32;
	tolex->box4space = 0;
	argv[i++] = 32;
	tolex->box4[tolex->box4index++] = argv[i];
	argv[i++] = 32;
	i += box4escapespace(argv + i, tolex);
	while (!((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && \
		argv[i] != '\0' && argv[i] != '<' && argv[i] != '>' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += box4inquote_mode2(argv + i, tolex);
		else if (argv[i] == 39)
			i += box4insinglequote_mode2(argv + i, tolex);
		else
		{
			tolex->box4[tolex->box4index++] = argv[i];
			argv[i++] = 32;
		}
	}
	return (i);
}
