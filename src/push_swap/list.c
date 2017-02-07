/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:03:19 by mburson           #+#    #+#             */
/*   Updated: 2017/02/06 20:03:21 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <push_swap.h>

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

int				lst_fnd_sml(t_list *stack)
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

int				lst_fnd_big(t_list *stack)
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

int				lst_size(t_list *list)
{
	int		size;

	if (!list)
		return (0);
	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
