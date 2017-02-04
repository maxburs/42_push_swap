/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:06:26 by mburson           #+#    #+#             */
/*   Updated: 2017/02/03 20:06:28 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

#include <stdio.h>

static int		exec_instr(t_state *state, int instr)
{
	if ((*g_func[instr])(state->a, state->b))
		return (1);
	ft_lstbadd(state->instr, ft_lstnew(&instr, sizeof(int)));
	if (g_flags & FLAG_VERBOSE)
		print_instr_res(state->a, state->b, g_instr[instr]);
	return (0);
}

static int		exec_n_instr(t_state *state, int instr, int n)
{
	while (n)
	{
		if (exec_instr(state, instr))
			return (1);
		n--;
	}
	return (0);
}

int				solve(t_list **instr, t_list **a, t_list **b)
{
	t_state		state;
	int			path;

	state.instr = instr;
	state.a = a;
	state.b = b;

	while (*a)
	{
		if ((path = path_to_smallest(*a)))
		{
			if (path > 0)
				exec_n_instr(&state, RA, path);
			else
				exec_n_instr(&state, RRA, path * -1);
		}
		exec_instr(&state, PB);
	}
	while (*b)
		exec_instr(&state, PA);
	return (0);
}
