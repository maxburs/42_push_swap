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

/*
** returns the number of rotate to get to the smallest int
** returns negative if its faster to rotate backwards
*/

int		path_to_smallest(t_list *stack)
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

int		find_smallest(t_list *stack)
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

int		find_biggest(t_list *stack)
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

/*
** returns true of spinning the list to the first element will put it in order
*/

int		lst_is_order(t_list *stack, int smallest)
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
