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
