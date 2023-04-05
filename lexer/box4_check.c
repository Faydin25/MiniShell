/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box4_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlcatraZ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:23:38 by AlcatraZ          #+#    #+#             */
/*   Updated: 2023/02/01 20:23:39 by AlcatraZ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	box4_check(t_shell *shell, t_lexout *tolex)
{
	int		i;
	int		a;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * 1000);
	while (tolex->box4 && tolex->box4[i] != '\0')
	{
		a = 0;
		while (tolex->box4[i] != ' ' && tolex->box4[i] != '\0')
			temp[a++] = tolex->box4[i++];
		temp[a] = '\0';
		box4_go_to_check(shell, temp);
		free(temp);
		temp = malloc(sizeof(char) * 1000);
		if (tolex->box4[i] != '\0')
			i++;
	}
	free(temp);
}

void	box4_go_to_check(t_shell *shell, char *argv)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (argv[i])
	{
		while (!(argv[i] != '<' && argv[i] != '>') && argv[i] != '\0')
		{
			i++;
			a++;
		}
		if (argv[i] != '\0')
			i++;
	}
	if (a == i)
		shell->err_code = 8;
}
