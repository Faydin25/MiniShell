/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlcatraZ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:26:41 by AlcatraZ          #+#    #+#             */
/*   Updated: 2023/02/01 20:26:41 by AlcatraZ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	isthere_flag(char *flag)
{
	if (flag && flag[0] == '-' && flag[1] == 'n' && flag[2] == '\0')
		return (2);
	return (1);
}

void	builtin_echo(t_node *node)
{
	int	a;

	a = isthere_flag(node->exec_args[1]);
	while (node->exec_args[a] != NULL)
	{
		printf("%s", node->exec_args[a]);
		if (node->exec_args[a + 1] != NULL)
		{
			printf(" ");
		}
		a++;
	}
	if (isthere_flag(node->exec_args[1]) == 1)
		printf("\n");
}
