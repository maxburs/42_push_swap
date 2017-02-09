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

#include <limits.h>

/*
** returns the int at the top of the stack in a linked list of ints
*/

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

/*
** returns the int next in the stack in a linked list of ints
*/

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
	if (lst_size(*a) < 13)
		return (small_hybrid_sort(&state));
	return (insertion_sort(&state));
}
