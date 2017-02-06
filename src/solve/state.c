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

static int		path_to_smallest_base(t_list *stack)
{
	int		front;
	int		back;
	int		smallest;

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

int				path_to_smallest(t_state *state, int stack_type)
{
	return (path_to_smallest_base(*stack_of_type(state, stack_type)));
}

static int		find_smallest_base(t_list *stack)
{
	int		smallest;

	smallest = *(int*)(stack->content);
	stack = stack->next;
	while (stack)
	{
		if (*(int*)(stack->content) < smallest)
		{
			smallest = *(int*)(stack->content);
		}
		stack = stack->next;
	}
	return (smallest);
}

int				find_smallest(t_state *state, int stack_type)
{
	return (find_smallest_base(*stack_of_type(state, stack_type)));
}

int				find_biggest_old(t_list *stack)
{
	int		biggest;

	biggest = *(int*)(stack->content);
	stack = stack->next;
	while (stack)
	{
		if (*(int*)(stack->content) > biggest)
		{
			biggest = *(int*)(stack->content);
		}
		stack = stack->next;
	}
	return (biggest);
}

int				find_biggest(t_state *state, int stack_type)
{
	return (find_biggest_old(*stack_of_type(state, stack_type)));
}

/*
** returns true of spinning the list to the first element will put it in order
*/

int				lst_is_order(t_list *stack, int smallest)
{
	int		found_smallest;
	int		last;
	int		first;

	found_smallest = 0;
	last = *(int*)(stack->content);
	first = last;
	if (last == smallest)
		found_smallest = 1;
	stack = stack->next;
	while (stack)
	{
		if (last > *(int*)(stack->content)
			&& (found_smallest || *(int*)(stack->content) != smallest))
			return (0);
		last = *(int*)(stack->content);
		if (last == smallest)
			found_smallest = 1;
		stack = stack->next;
	}
	if (first < last)
		return (0);
	return (1);
}

int				stack_size(t_list *stack)
{
	int		size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_list			*ft_lst_last(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

int			last_in_stack(t_state *state, int stack_type)
{
	if (stack_type == STACK_A)
		return (*(int*)((ft_lst_last(*(state->a)))->content));
	else
		return (*(int*)((ft_lst_last(*(state->b)))->content));
}
