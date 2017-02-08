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
/*
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
*/
/*
** moves a stack to the smallest integer in it
** bubble sorting along the way
*/
/*
static int		goto_smallest(t_state *state, int stack_type)
{
	int		move;
	int		smallest;
	int		biggest;

	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- starting: goto_smallest\n\n");
	smallest = find_smallest(state, stack_type);
	biggest = find_biggest(state, stack_type);
	move = pick_move_type(state, stack_type);
	while (!(top_of_stack(state, stack_type) == smallest
				&& last_in_stack(state, stack_type) == biggest))
	{
			exec_instr(state, move);
	}
	return (0);
}

static int		find_smallest_path(t_state *state, int &bmove, int &amove)
{

}
*/
int				insertion_sort(t_state *state)
{
	/*
	while (*(state->a))
	{
		
		if (stack_in_order(*(state->a)))
		{
			if (g_flags & FLAG_VERBOSE)
				ft_putstr("   --- stack 'a' in order, finalizing...\n\n");
			break ;
		}
		exec_instr(state, PB);
	}
	goto_smallest(state, STACK_A);
	while (*(state->b))
		exec_instr(state, PA);
	*/
	int front;
	int back;

	paths_to_insert(*stack_of_type(state, STACK_A), 3, &front, &back);
	printf("front: %d\n", front);
	printf("back: %d\n", back);
	printf("path to end: %d\n", path_to_end(state, STACK_A));
	return (0);
}
