/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:36:26 by mburson           #+#    #+#             */
/*   Updated: 2017/02/05 19:36:28 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int		exec_instr(t_state *state, int instr)
{
	if ((*g_func[instr])(state->a, state->b))
		return (1);
	ft_lstbadd(state->instr, ft_lstnew(&instr, sizeof(int)));
	if (g_flags & FLAG_VERBOSE)
		print_instr_res(state->a, state->b, g_instr[instr]);
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

int		try_rbubble(t_state *state, int stack_type, int reverse)
{
	if ((!reverse && top_of_stack(state, stack_type) < next_in_stack(state, stack_type))
		|| (reverse && top_of_stack(state, stack_type) > next_in_stack(state, stack_type)))
	{
		if (stack_type == STACK_A)
			exec_instr(state, SA);
		else if (stack_type == STACK_B)
			exec_instr(state, SB);
		return (1);
	}
	return (0);
}

int		top_of_stack(t_state *state, int stack_type)
{
	if (stack_type == STACK_A)
	{
		return (*(int*)((*(state->a))->content));
	}
	else if (stack_type == STACK_B)
	{
		return (*(int*)((*(state->b))->content));
	}
	return (0);
}

int		next_in_stack(t_state *state, int stack_type)
{
	if (stack_type == STACK_A)
	{
		return (*(int*)(((*(state->a))->next)->content));
	}
	else if (stack_type == STACK_B)
	{
		return (*(int*)(((*(state->b))->next)->content));
	}
	return (0);
}

t_list	**stack_of_type(t_state *state, int stack_type)
{
	return (stack_type == STACK_A ? state->a : state->b);
}

int		solve(t_list **instr, t_list **a, t_list **b)
{
	t_state		state;

	state.instr = instr;
	state.a = a;
	state.b = b;
	//return (hybrid_sort(&state));
	//return (merge_sort_old(&state));
	return (merge_sort(&state));
}
