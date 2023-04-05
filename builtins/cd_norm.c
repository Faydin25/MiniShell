/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlcatraZ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:26:26 by AlcatraZ          #+#    #+#             */
/*   Updated: 2023/02/01 20:26:27 by AlcatraZ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_home(t_shell *shell)
{
	char	*dup;
	int		i;

	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "HOME=", 5))
			dup = ft_strdup_env(shell->env[i]);
		i++;
	}
	return (dup);
}
