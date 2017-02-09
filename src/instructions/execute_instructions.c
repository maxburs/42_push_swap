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
#include <stdbool.h>

char const *const	g_instr[] = {
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

int (*const			g_func[])(t_list **a, t_list **b) = {
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

static void		invalid_operation(char *operation, _Bool verbose)
{
	if (verbose == false)
		return ;
	ft_putstr_fd("invalid operation: ->", 2);
	ft_putstr_fd(operation, 2);
	ft_putstr_fd("<-\n\n", 2);
}

int				execute_instructions(t_list **a, t_list **b, char **instr,
										_Bool verbose)
{
	int		i;

	if (verbose)
		ft_putchar('\n');
	while (*instr)
	{
		i = 0;
		while (g_instr[i])
		{
			if (ft_strequ(*instr, g_instr[i]))
			{
				(*g_func[i])(a, b);
				print_instr_res(a, b, *instr, verbose);
				break ;
			}
			i++;
		}
		if (!g_instr[i])
			invalid_operation(*instr, verbose);
		instr++;
	}
	return (0);
}
