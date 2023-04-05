/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlcatraZ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:21:59 by AlcatraZ          #+#    #+#             */
/*   Updated: 2023/02/01 20:22:00 by AlcatraZ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	string_length(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

int	check_newline(char *ptr)
{
	if (!ptr)
		return (1);
	while (*ptr)
	{
		if (*ptr == '\n')
			return (0);
		ptr++;
	}
	return (1);
}

char	*append_string(char *str, char *buf)
{
	char	*result;
	int		i;
	int		j;

	if (!buf)
		return (NULL);
	if (!str)
	{	
		str = malloc(1);
		*str = '\0';
	}
	result = malloc(string_length(str) + string_length(buf) + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (str[++i])
		result[i] = str[i];
	j = 0;
	while (buf[j])
		result[i++] = buf[j++];
	result[i] = '\0';
	free(str);
	return (result);
}
