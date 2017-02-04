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
#include <push_swap.h>

const char * const 		g_instr[] = {
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr",
	NULL
};

int (* const			g_func[])(t_list **a, t_list **b) = {
	&exec_sa,
	&exec_sb,
	&exec_ss,
	&exec_pa,
	&exec_pb,
	&exec_ra,
	&exec_rb,
	&exec_rr,
	&exec_rra,
	&exec_rrb,
	&exec_rrr,
	NULL
};

static void		print_instr_res(t_list **a, t_list **b, char *instr)
{
	ft_putstr("operation: ");
	ft_putstr(instr);
	ft_putstr("\n");
	print_stacks(*a, *b);
}

int				execute_instructions(t_list **a, t_list **b, char **instr)
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
				(*g_func[i])(a, b);
				if (g_flags & FLAG_VERBOSE)
					print_instr_res(a, b, *instr);
				break ;
			}
			i++;
		}
		instr++;
	}
	return (0);
}