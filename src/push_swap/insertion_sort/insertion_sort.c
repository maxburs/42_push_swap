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

void			print_path(t_path path)
{
	if (!(g_flags & FLAG_VERBOSE))
		return ;
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

static void		finish(t_state *state)
{
	int		end_path;

	end_path = path_to_end(state, STACK_B);
	if (g_flags & FLAG_VERBOSE)
	{
		ft_putstr("   --- end path: ");
		ft_putnbr(end_path);
		ft_putchar('\n');
	}
	if (end_path > 0)
		exec_n_instr(state, RB, end_path);
	else
		exec_n_instr(state, RRB, end_path * -1);
	while (*(state->b))
		exec_instr(state, PA);
}

/*
** executes on a path
*/

static void		exec_path(t_state *state, t_path path)
{
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- path:\n");
	print_path(path);
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

int				insertion_sort(t_state *state)
{
	t_path	path;

	while (*(state->a))
	{
		path = find_best_path(state);
		exec_path(state, path);
		if (g_flags & FLAG_VERBOSE)
			ft_putstr("   --- best path completed, pushing...\n\n");
		exec_instr(state, PB);
	}
	finish(state);
	return (0);
}