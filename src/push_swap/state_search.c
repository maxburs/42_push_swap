/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:37:37 by mburson           #+#    #+#             */
/*   Updated: 2017/02/03 21:37:39 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <push_swap.h>

/*
** returns the number of rotate to get to the smallest int
** returns negative if its faster to rotate backwards
*/

int			path_to_smallest(t_state *state, int stack_type)
{
	t_list	*stack;
	int		front;
	int		back;
	int		smallest;

	stack = *stack_of_type(state, stack_type);
	front = 0;
	back = 0;
	if (!stack)
		return (0);
	smallest = *(int*)(stack->content);
	stack = stack->next;
	while (stack)
	{
		back++;
		if (*(int*)(stack->content) < smallest)
		{
			smallest = *(int*)(stack->content);
			front += back;
			back = 0;
		}
		stack = stack->next;
	}
	back++;
	return (front < back ? front : -1 * back);
}

int			find_smallest(t_state *state, int stack_type)
{
	return (lst_fnd_sml(*stack_of_type(state, stack_type)));
}

int			find_biggest(t_state *state, int stack_type)
{
	return (lst_fnd_big(*stack_of_type(state, stack_type)));
}

int			last_in_stack(t_state *state, int stack_type)
{
	if (stack_type == STACK_A)
		return (*(int*)((ft_lst_last(*(state->a)))->content));
	else
		return (*(int*)((ft_lst_last(*(state->b)))->content));
}
