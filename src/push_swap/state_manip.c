/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:38:25 by mburson           #+#    #+#             */
/*   Updated: 2017/02/06 20:38:27 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int		exec_instr(t_state *state, int instr)
{
	if ((state->op_func[instr])(state->a, state->b))
		return (1);
	ft_lstbadd(state->instr, ft_lstnew(&instr, sizeof(int)));
	if (state->verbose)
		print_instr_res(state->a, state->b, state->op[instr], state->verbose);
	return (0);
}

int		exec_n_instr(t_state *state, int instr, int n)
{
	while (n)
	{
		if (exec_instr(state, instr))
			return (1);
		n--;
	}
	return (0);
}
