/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:34:19 by mburson           #+#    #+#             */
/*   Updated: 2017/02/05 19:34:21 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <stdlib.h>

static int		goto_end_of_chunk(t_state *state, t_meta *meta)
{
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- incrementing past chunk\n\n");
	print_meta(meta);
	meta->size_remaining -= meta->chunk_left;
	while (meta->chunk_left)
	{
		exec_instr(state, RA);
		meta->chunk_left--;
	}
	print_meta(meta);
	return (0);
}

/*
** sets chunk_size and chunk_left for the next chunk
*/

static int		init_next_chunk(t_meta *meta)
{
	if (meta->sort_size < meta->size_remaining)
		meta->chunk_size = meta->sort_size;
	else
		meta->chunk_size = meta->size_remaining;
	meta->chunk_left = meta->chunk_size;
	return (0);
}

static void		merge_startup(t_state *state, t_meta *meta)
{
	meta->sort_size = 2;
	meta->total_size = lst_size(*(state->a));
	meta->bubble_map = build_order_map(meta->total_size / 2 + 1);
	meta->bubble_index = 0;
}

static void		loop_startup(t_meta *meta)
{
	if (g_flags & FLAG_VERBOSE)
	{
		ft_putstr("   --- --- --- --- --- --- --- LOOP START");
		ft_putstr(" --- --- --- --- --- --- ---\n\n");
	}
	meta->size_remaining = meta->total_size;
	meta->reverse_map = build_order_map(meta->total_size /
		(meta->sort_size * 2) + 1);
	meta->map_index = 0;
	print_meta(meta);
}

int				merge_sort(t_state *state)
{
	t_meta		meta;

	merge_startup(state, &meta);
	while (meta.sort_size < meta.total_size)
	{
		loop_startup(&meta);
		while (meta.size_remaining)
		{
			merge_bubble(state, &meta);
			init_next_chunk(&meta);
			merge_chunk_to_b(state, &meta);
			init_next_chunk(&meta);
			merge_bubble(state, &meta);
			merge_chunks(state, &meta);
			goto_end_of_chunk(state, &meta);
		}
		if (meta.sort_size == 2)
			free(meta.bubble_map);
		meta.sort_size *= 2;
		free(meta.reverse_map);
	}
	return (0);
}
