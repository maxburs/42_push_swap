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

/*
** if the next to elements in the stack type are out of order swap them
** return 1 if a swap was made, otherwise return 0
*/

int		try_bubble(t_state *state, int stack_type)
{
	if (top_of_stack(state, stack_type) > next_in_stack(state, stack_type))
	{
		if (stack_type == STACK_A)
			exec_instr(state, SA);
		else if (stack_type == STACK_B)
			exec_instr(state, SB);
		return (1);
	}
	return (0);
}

/*
** similar to try_bubble but lets you specify the sorting direction
*/

int		try_rbubble(t_state *state, int stack_type, int reverse)
{
	if ((!reverse && top_of_stack(state, stack_type)
			> next_in_stack(state, stack_type))
		|| (reverse && top_of_stack(state, stack_type)
			< next_in_stack(state, stack_type)))
	{
		if (stack_type == STACK_A)
			exec_instr(state, SA);
		else if (stack_type == STACK_B)
			exec_instr(state, SB);
		return (1);
	}
	return (0);
}
