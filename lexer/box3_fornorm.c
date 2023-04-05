/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box3_fornorm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlcatraZ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:23:19 by AlcatraZ          #+#    #+#             */
/*   Updated: 2023/02/01 20:23:20 by AlcatraZ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	thirdbox_is_null(t_lexout *tolex)
{
	if (tolex->box3index == 0)
	{
		free(tolex->box3);
		tolex->box3 = NULL;
		return (1);
	}
	return (0);
}
