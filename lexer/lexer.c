/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlcatraZ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:24:34 by AlcatraZ          #+#    #+#             */
/*   Updated: 2023/02/01 20:24:35 by AlcatraZ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer(char *argv, t_lexout *tolex, t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->err_code == 5)
		return (0);
	fillboxes(tolex, shell);
	fourthbox(argv, tolex);
	is_fourthbox_null(tolex);
	box4_check(shell, tolex);
	i += before_firstbox(argv, tolex);
	i += before_secondbox(argv + i, tolex);
	is_second_box_null(tolex);
	i += before_thirdbox(argv + i, tolex);
	if (tolex->box1 == NULL && tolex->box4 == NULL && tolex->totalnode > 1)
		shell->err_code = 6;
	if (argv[0] != '|')
		create_node(shell, tolex);
	else if (argv[0] == '|')
		shell->err_code = 4;
	tolex->currentnode += 1;
	if (argv[i] == '|' && argv[0] != '|')
		lexer(argv + i + 1, tolex, shell);
	shell->totalnode = tolex->totalnode;
	return (1);
}
