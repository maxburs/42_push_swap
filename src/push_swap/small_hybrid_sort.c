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

static int		pick_move_type(t_state *state, int stack_type)
{
	if (stack_type == STACK_A)
	{
		if (path_to_smallest(state, stack_type) > 0)
			return (RA);
		else
			return (RRA);
	}
	else
	{
		if (path_to_smallest(state, stack_type) > 0)
			return (RB);
		else
			return (RRB);
	}
}

/*
** moves a stack to the smallest integer in it
** bubble sorting along the way
*/

static int		goto_smallest_bubble(t_state *state, int stack_type)
{
	int		smallest;
	int		move;
	int		biggest;

	if (state->verbose)
		ft_putstr("   --- starting: goto_smallest_bubble\n\n");
	smallest = find_smallest(state, stack_type);
	biggest = find_biggest(state, stack_type);
	move = pick_move_type(state, stack_type);
	while (top_of_stack(state, stack_type) != smallest)
	{
		if (!((top_of_stack(state, stack_type) == biggest)
			&& (next_in_stack(state, stack_type) == smallest)))
		{
			if (!try_bubble(state, stack_type))
				exec_instr(state, move);
		}
		else
			exec_instr(state, move);
	}
	if (state->verbose)
		ft_putstr("   --- ending: goto_smallest_bubble\n\n");
	return (0);
}

int				small_hybrid_sort(t_state *state)
{
	int		size;

	size = lst_size(*(state->a));
	while (size > 3)
	{
		goto_smallest_bubble(state, STACK_A);
		if (stack_in_order(*(state->a)))
		{
			if (state->verbose)
				ft_putstr("   --- stack 'a' in order, finalizing...\n\n");
			break ;
		}
		exec_instr(state, PB);
		size--;
	}
	sort_3(state, STACK_A);
	while (*(state->b))
		exec_instr(state, PA);
	return (0);
}
