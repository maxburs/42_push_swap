/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:10:22 by mburson           #+#    #+#             */
/*   Updated: 2017/02/26 15:10:24 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void						sort_3(t_state *state, int stack_type)
{
	t_list	*stack;
	int		smallest;

	if (state->verbose)
		ft_putstr("\n   --- sort 3 start\n\n");
	smallest = find_smallest(state, stack_type);
	stack = *stack_of_type(state, stack_type);
	if (!lst_is_order(stack, smallest))
	{
		exec_instr(state, SA);
	}
	if (next_in_stack(state, stack_type) == smallest)
		exec_instr(state, RA);
	else if (last_in_stack(state, stack_type) == smallest)
		exec_instr(state, RRA);
}
