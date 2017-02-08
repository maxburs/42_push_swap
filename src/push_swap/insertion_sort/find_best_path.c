/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:45:53 by mburson           #+#    #+#             */
/*   Updated: 2017/02/07 17:45:54 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <limits.h>

#include <stdio.h>

/*
** sets forward path and backwards path to the the number of moves to
**    get the given stack to accept the given number and maintain reverse order
*/

int					try_largest(t_list *stack, int insert_me,
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
	back++;
	while (stack && stack->next)
	{
		back++;
		stack = stack->next;
	}
	//printf("path backwards: %zu\n", back);
	//printf("path forwards: %zu\n", front);
	//printf("\n");
	*forward_path = front;
	*backwards_path = back;
	return (1);
}

int					try_smallest(t_list *stack, int insert_me,
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
	while (stack && stack->next)
	{
		back++;
		stack = stack->next;
	}
	//printf("path backwards: %zu\n", back);
	//printf("path forwards: %zu\n", front);
	//printf("\n");
	*forward_path = front;
	*backwards_path = back;
	return (1);
}

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

/*
** determines the number of comperations to compete a path
*/

int		spy(int print_me)
{
	ft_putchar('\n');
	ft_putnbr(print_me);
	ft_putchar('\n');
	return (print_me);
}

static size_t		operations_to_complete(t_path path)
{
	//ft_putstr("   --- comparing path:\n");
	//print_path(path);
	if (path.a_dir !=  path.b_dir)
	{
		return (path.a_len + path.b_len);
	}
	else if (path.a_len > path.b_len)
	{
		return (path.a_len);
	}
	else
	{
		return (path.b_len);
	}
}

static void		update_if_bigger(size_t *best_op_time, t_path *best_path,
									t_path *new_path)
{
	size_t		ops;

	ops = operations_to_complete(*new_path);
	if (*best_op_time > ops)
	{
		*best_op_time = ops;
		*best_path = *new_path;
	}
}

/*
** finds the shorest path out of all possible paths
*/

t_path			find_best_path(t_state *state)
{
	t_list		*stack_a;
	size_t		best_op_time;
	t_path		best_path;
	t_path		new_path;

	size_t		a_forward;
	size_t		a_backward;
	size_t		b_forward;
	size_t		b_backward;

	stack_a = *stack_of_type(state, STACK_A);
	best_op_time = INT_MAX;
	a_forward = 0;
	a_backward = lst_size(*stack_of_type(state, STACK_A));
	while (stack_a)
	{
		//ft_putstr("      --- looking to insert: ");
		//ft_putnbr(*(int*)(stack_a->content));
		//ft_putchar('\n');

		how_to_insert(*stack_of_type(state, STACK_B), *(int*)(stack_a->content),
							&b_forward, &b_backward);
		new_path.a_dir = FORWARD;
		new_path.b_dir = FORWARD;
		new_path.a_len = a_forward;
		new_path.b_len = b_forward;
		update_if_bigger(&best_op_time, &best_path, &new_path);

		new_path.b_dir = BACKWARD;
		new_path.b_len = b_backward;
		update_if_bigger(&best_op_time, &best_path, &new_path);
		
		new_path.a_dir = BACKWARD;
		new_path.a_len = a_backward;
		update_if_bigger(&best_op_time, &best_path, &new_path);
		
		new_path.b_dir = FORWARD;
		new_path.b_len = b_forward;
		update_if_bigger(&best_op_time, &best_path, &new_path);

		stack_a = stack_a->next;
		a_forward++;
		a_backward--;
	}
	return (best_path);
}
