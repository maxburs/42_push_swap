/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 23:47:17 by mburson           #+#    #+#             */
/*   Updated: 2017/01/29 23:47:18 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <checker.h>

const char * const 		g_instr[] = {
	"sa",
//	"sb",
//	"ss",
//	"pa",
//	"pb",
//	"ra",
//	"rb",
//	"rr",
//	"rra",
//	"rrb",
//	"rrr",
	NULL
};

static int (* const		func[])(t_list **a, t_list **b) = {
	&exec_sa,
//	&exec_sb,
//	&exec_ss,
//	&exec_pa,
//	&exec_pb,
//	&exec_ra,
//	&exec_rb,
//	&exec_rr,
//	&exec_rra,
//	&exec_rrb,
//	&exec_rrr,
	NULL
};

int		execute_instructions(t_list **a, t_list **b, char **instr)
{
	int		i;

	if (g_flags & FLAG_VERBOSE)
		ft_putchar('\n');
	while (*instr)
	{
		i = 0;
		while (g_instr[i])
		{
			if (ft_strequ(*instr, g_instr[i]))
			{
				(*func[i])(a, b);
				break ;
			}
			i++;
		}
		instr++;
	}
	return (0);
}
