/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:06:26 by mburson           #+#    #+#             */
/*   Updated: 2017/02/03 20:06:28 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <limits.h>
#include <stdbool.h>

void			print_path(t_path path)
{
	ft_putstr("move stack a ");
	if (path.a_len > INT_MAX)
		ft_putstr("REAL DAMN HUGE");
	else
		ft_putnbr((int)path.a_len);
	if (path.a_dir == FORWARD)
		ft_putstr(" forward\n");
	else
		ft_putstr(" backwards\n");
	ft_putstr("move stack b ");
	if (path.b_len > INT_MAX)
		ft_putstr("REAL DAMN HUGE");
	else
		ft_putnbr((int)path.b_len);
	if (path.b_dir == FORWARD)
		ft_putstr(" forward\n");
	else
		ft_putstr(" backwards\n");
	ft_putchar('\n');
}

/*
** moves stack b into a reverse sorted position and then pushes it onto stack a
*/

static void		order_stack_b(t_state *state)
{
	int		end_path;

	end_path = path_to_end(state, STACK_B);
	if (state->verbose)
	{
		ft_putstr("   --- end path: ");
		ft_putnbr(end_path);
		ft_putchar('\n');
	}
	if (end_path > 0)
		exec_n_instr(state, RB, end_path);
	else
		exec_n_instr(state, RRB, end_path * -1);
}

/*
** executes on a path
*/

static void		exec_path(t_state *state, t_path path)
{
	if (state->verbose)
	{
		ft_putstr("   --- path:\n");
		print_path(path);
	}
	if (path.a_dir == path.b_dir)
	{
		while (path.a_len && path.b_len)
		{
			exec_instr(state, path.a_dir == FORWARD ? RR : RRR);
			path.a_len--;
			path.b_len--;
		}
	}
	while (path.a_len)
	{
		exec_instr(state, path.a_dir == FORWARD ? RA : RRA);
		path.a_len--;
	}
	while (path.b_len)
	{
		exec_instr(state, path.b_dir == FORWARD ? RB : RRB);
		path.b_len--;
	}
}

static void		merge_stacks(t_state *state)
{
	int		left;

	left = lst_size(*stack_of_type(state, STACK_A));
	if (state->verbose)
		ft_putstr("   --- merging stacks\n\n");
	while (left && *(state->b))
	{
		if (last_in_stack(state, STACK_A) > top_of_stack(state, STACK_B))
		{
			exec_instr(state, RRA);
			left--;
		}
		else
			exec_instr(state, PA);
	}
	while (*(state->b))
		exec_instr(state, PA);
	while (left)
	{
		exec_instr(state, RRA);
		left--;
	}
}

int				insertion_sort(t_state *state)
{
	t_path	path;
	int		size;

	size = lst_size(*stack_of_type(state, STACK_A));
	while (size > 3)
	{
		path = find_best_path(state);
		exec_path(state, path);
		if (state->verbose)
			ft_putstr("   --- best path completed, pushing...\n\n");
		exec_instr(state, PB);
		size--;
	}
	order_stack_b(state);
	size = lst_size(*stack_of_type(state, STACK_A));
	if (size == 3)
		sort_3(state, STACK_A);
	else if (size == 2
		&& next_in_stack(state, STACK_A) < top_of_stack(state, STACK_A))
		exec_instr(state, SA);
	if (*stack_of_type(state, STACK_B))
		merge_stacks(state);
	return (0);
}
