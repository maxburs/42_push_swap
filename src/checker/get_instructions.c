/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:23:32 by mburson           #+#    #+#             */
/*   Updated: 2017/02/06 20:23:33 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <push_swap.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int		get_instructions(char ***instr_return)
{
	char	buff[BUFF_SIZE];
	t_lstr	*l;
	char	*instr_raw;
	int		res;

	l = NULL;
	while ((res = read(0, buff, BUFF_SIZE)))
	{
		ft_lstr_add(&l, ft_strndup(buff, res), false);
	}
	instr_raw = ft_lstr_finish(&l);
	*instr_return = ft_strsplit(instr_raw, '\n');
	free(instr_raw);
	if (g_flags & FLAG_VERBOSE)
		print_instructions(*instr_return);
	return (0);
}
