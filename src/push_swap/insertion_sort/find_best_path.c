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

/*
** determines the number of comperations to compete a path
*/

static size_t		operations_to_complete(t_path path)
{
	if (path.a_dir != path.b_dir)
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

/*
** updates best_op_time and best_path if new_path is shorter
*/

static void			update_if_bigger(t_paths_meta *meta)
{
	size_t		ops;

	ops = operations_to_complete(meta->new_path);
	if (meta->best_op_time > ops)
	{
		meta->best_op_time = ops;
		meta->best_path = meta->new_path;
	}
}

static void			try_path_combinations(t_paths_meta *meta)
{
	meta->new_path.a_dir = FORWARD;
	meta->new_path.b_dir = FORWARD;
	meta->new_path.a_len = meta->a_forward;
	meta->new_path.b_len = meta->b_forward;
	update_if_bigger(meta);
	meta->new_path.b_dir = BACKWARD;
	meta->new_path.b_len = meta->b_backward;
	update_if_bigger(meta);
	meta->new_path.a_dir = BACKWARD;
	meta->new_path.a_len = meta->a_backward;
	update_if_bigger(meta);
	meta->new_path.b_dir = FORWARD;
	meta->new_path.b_len = meta->b_forward;
	update_if_bigger(meta);
}

/*
** finds the shorest path out of all possible paths
*/

t_path				find_best_path(t_state *state)
{
	t_paths_meta	meta;
	t_list			*stack_a;

	stack_a = *stack_of_type(state, STACK_A);
	meta.best_op_time = INT_MAX;
	meta.a_forward = 0;
	meta.a_backward = lst_size(*stack_of_type(state, STACK_A));
	while (stack_a)
	{
		how_to_insert(*stack_of_type(state, STACK_B), *(int*)(stack_a->content),
							&meta.b_forward, &meta.b_backward);
		try_path_combinations(&meta);
		stack_a = stack_a->next;
		meta.a_forward++;
		meta.a_backward--;
	}
	return (meta.best_path);
}
