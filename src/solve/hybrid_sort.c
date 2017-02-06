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

/*
** moves a stack to the smallest integer in it
** bubble sorting along the way
*/

static int		goto_smallest_bubble(t_state *state, int stack_type)
{
	int		smallest;
	t_list	**stack;
	int		move;
	int		biggest;

	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- starting: goto_smallest_bubble\n\n");
	stack = stack_type == STACK_A ? state->a : state->b;
	smallest = find_smallest(*stack_of_type(state, stack_type));
	biggest = find_biggest(*stack_of_type(state, stack_type));
	move = (path_to_smallest(state, stack_type) > 0) ? (stack_type == STACK_A ? RA : RB)
				: (stack_type == STACK_A ? RRA : RRB);
	while (top_of_stack(state, stack_type) != smallest)
	{
		if ((top_of_stack(state, stack_type) != biggest)
			&& (next_in_stack(state, stack_type) != smallest))
		{
			if (!try_bubble(state, stack_type))
				exec_instr(state, move);
		}
		else
			exec_instr(state, move);
	}
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- ending: goto_smallest_bubble\n\n");
	return (0);
}

int				hybrid_sort(t_state *state)
{
	while (*(state->a))
	{
		goto_smallest_bubble(state, STACK_A);
		if (stack_in_order(*(state->a)))
		{
			if (g_flags & FLAG_VERBOSE)
				ft_putstr("   --- stack 'a' in order, finalizing...\n\n");
			break ;
		}
		exec_instr(state, PB);
	}
	while (*(state->b))
		exec_instr(state, PA);
	return (0);
}
