/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:34:45 by mburson           #+#    #+#             */
/*   Updated: 2017/02/06 14:34:47 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static int		stack_b_first(t_state *state, t_meta *meta)
{
	if (!meta->reverse_map[meta->map_spot]
		&& top_of_stack(state, STACK_A) >= top_of_stack(state, STACK_B))
		return (1);
	else if (meta->reverse_map[meta->map_spot]
		&& top_of_stack(state, STACK_A) <= top_of_stack(state, STACK_B))
		return (1);
	return (0);
}

static void		move_remaining_stack_b(t_state *state, t_meta *meta)
{
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- nothing left in chunk, moving rest of stack b\n\n");
	while (*(state->b))
	{
		exec_instr(state, PA);
		exec_instr(state, RA);
		meta->chunk_size++;
	}
}

static void		move_stack_b(t_state *state, t_meta *meta)
{
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- stack b first\n");
	exec_instr(state, PA);
	exec_instr(state, RA);
	meta->chunk_size++;
}

static void		move_stack_a(t_state *state, t_meta *meta)
{
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- stack a first\n");
	exec_instr(state, RA);
	meta->size_remaining--;
	meta->chunk_left--;
}

int				merge_chunks(t_state *state, t_meta *meta)
{
	if (g_flags & FLAG_VERBOSE)
	{
		ft_putstr("   --- merging\n");
		if (meta->reverse_map[meta->map_spot])
			ft_putstr("         chunk is being sorted IN REVERSE\n\n");
		else
			ft_putstr("         chunk is being sorted IN ORDER\n\n");
	}
	print_meta(meta);
	while (meta->chunk_left > 0 && *(state->b))
	{
		if (stack_b_first(state, meta))
		{
			move_stack_b(state, meta);
		}
		else
		{
			move_stack_a(state, meta);
		}
	}
	move_remaining_stack_b(state, meta);
	meta->map_spot++;
	return (0);
}
