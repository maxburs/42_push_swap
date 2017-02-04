/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 00:46:05 by mburson           #+#    #+#             */
/*   Updated: 2017/01/31 00:46:07 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <string.h>
#include <checker.h>
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
		if (buff[res - 1] == '\n')
		{
			buff[res - 1] = ' ';
			ft_lstr_add(&l, ft_strndup(buff, res), false);
			break ;
		}
		ft_lstr_add(&l, ft_strndup(buff, res), false);
	}
	instr_raw = ft_lstr_finish(&l);
	*instr_return = ft_strsplit(instr_raw, ' ');
	free(instr_raw);
	if (g_flags & FLAG_VERBOSE)
		print_instructions(*instr_return);
	return (0);
}
