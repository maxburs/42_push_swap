/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_to_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:24:58 by mburson           #+#    #+#             */
/*   Updated: 2017/02/08 17:24:59 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static int		try_largest(t_list *stack, int insert_me,
								size_t *forward_path, size_t *backwards_path)
{
	size_t		front;
	int			largest;

	largest = lst_fnd_big(stack);
	if (insert_me < largest)
		return (0);
	front = 0;
	if (*(int*)(ft_lst_last(stack)->content) == largest)
		while (stack && *(int*)(stack->content) == largest)
		{
			front++;
			stack = stack->next;
		}
	while (stack && *(int*)(stack->content) != largest && (stack = stack->next))
	{
		front++;
	}
	while (stack && (*(int*)(stack->content) == insert_me))
		stack = stack->next;
	*forward_path = front;
	*backwards_path = lst_size(stack);
	return (1);
}

static int		try_smallest(t_list *stack, int insert_me,
								size_t *forward_path, size_t *backwards_path)
{
	size_t		front;
	int			smallest;

	smallest = lst_fnd_sml(stack);
	if (insert_me > smallest)
		return (0);
	if (*(int*)(ft_lst_last(stack)->content) == smallest)
	{
		*forward_path = 0;
		*backwards_path = 0;
		return (1);
	}
	front = 1;
	while (stack && (*(int*)(stack->content) != smallest))
	{
		front++;
		stack = stack->next;
	}
	while (stack && (*(int*)(stack->content) == insert_me))
		stack = stack->next;
	*forward_path = front;
	*backwards_path = lst_size(stack) - 1;
	return (1);
}

/*
** sets forward path and backwards path to the the number of moves to
**    get the given stack to accept the given number and maintain reverse order
*/

void			how_to_insert(t_list *stack, int insert_me,
								size_t *forward_path, size_t *backwards_path)
{
	size_t		front;

	if (!stack || (insert_me >= *(int*)(stack->content)
			&& insert_me <= *(int*)(ft_lst_last(stack)->content)))
	{
		*forward_path = 0;
		*backwards_path = 0;
		return ;
	}
	if (try_largest(stack, insert_me, forward_path, backwards_path)
		|| try_smallest(stack, insert_me, forward_path, backwards_path))
		return ;
	front = 0;
	while ((stack->next) && !(*(int*)(stack->content) >= insert_me
			&& *(int*)((stack->next)->content) <= insert_me))
	{
		front++;
		stack = stack->next;
	}
	while (stack->next && (*(int*)((stack->next)->content) == insert_me))
		stack = stack->next;
	front++;
	*forward_path = front;
	*backwards_path = lst_size(stack) - 1;
}
