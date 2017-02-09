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

#include <stdio.h>

static int				try_largest(t_list *stack, int insert_me,
								size_t *forward_path, size_t *backwards_path)
{
	size_t		front;
	size_t		back;
	int			largest;

	largest = lst_fnd_big(stack);
	front = 0;
	back = 0;
	if (insert_me < largest)
		return (0);
	//printf("is largest!!\n\n");
	//printf("largest: %d\n", largest);
	//printf("insert me: %d\n", insert_me);
	if (*(int*)(ft_lst_last(stack)->content) == largest)
	{
		while (stack && *(int*)(stack->content) == largest)
		{
			front++;
			stack = stack->next;
		}
	}
	while (stack && stack->next && *(int*)(stack->content) != largest)
	{
		front++;
		stack = stack->next;
	}
	while (stack && (*(int*)(stack->content) == insert_me))
	{
		stack = stack->next;
	}
	back += lst_size(stack);
	//printf("path backwards: %zu\n", back);
	//printf("path forwards: %zu\n", front);
	//printf("\n");
	*forward_path = front;
	*backwards_path = back;
	return (1);
}

static int				try_smallest(t_list *stack, int insert_me,
								size_t *forward_path, size_t *backwards_path)
{
	size_t		front;
	size_t		back;
	int			smallest;

	smallest = lst_fnd_sml(stack);
	front = 0;
	back = 0;
	if (insert_me > smallest)
		return (0);
	//printf("is smallest!!\n\n");
	//printf("smallest: %d\n", smallest);
	//printf("insert me: %d\n", insert_me);
	if (*(int*)(ft_lst_last(stack)->content) == smallest)
	{
		*forward_path = 0;
		*backwards_path = 0;
		return (1);
	}
	front++;
	while (stack && (*(int*)(stack->content) != smallest))
	{
		front++;
		stack = stack->next;
	}
	while (stack && (*(int*)(stack->content) == insert_me))
	{
		stack = stack->next;
	}
	back += lst_size(stack) - 1;
	//printf("path backwards: %zu\n", back);
	//printf("path forwards: %zu\n", front);
	//printf("\n");
	*forward_path = front;
	*backwards_path = back;
	return (1);
}

/*
** sets forward path and backwards path to the the number of moves to
**    get the given stack to accept the given number and maintain reverse order
*/

void				how_to_insert(t_list *stack, int insert_me,
								size_t *forward_path, size_t *backwards_path)
{
	size_t		front;
	size_t		back;

	front = 0;
	back = 0;

	if (!stack/* || !stack->next*/)
	{
		*forward_path = 0;
		*backwards_path = 0;
		return ;
	}
	if (try_largest(stack, insert_me, forward_path, backwards_path))
		return ;
	if (try_smallest(stack, insert_me, forward_path, backwards_path))
		return ;

	if ((insert_me >= *(int*)(stack->content)
			&& insert_me <= *(int*)(ft_lst_last(stack)->content)))
	{
		*forward_path = 0;
		*backwards_path = 0;
		return ;
	}
	while ((stack->next)
			&& !(*(int*)(stack->content) >= insert_me
			&& *(int*)((stack->next)->content) <= insert_me))
	{
		front++;
		stack = stack->next;
	}
	while (stack->next && (*(int*)((stack->next)->content) == insert_me))
	{
		stack = stack->next;
	}
	while (stack->next)
	{
		back++;
		stack = stack->next;
	}
	front++;
	//printf("path backwards: %zu\n", back);
	//printf("path forwards: %zu\n", front);
	//printf("\n");
	*forward_path = front;
	*backwards_path = back;
}
