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

void			print_meta(t_meta *meta)
{
	if (!(g_flags & FLAG_VERBOSE))
		return ;
	ft_putstr("   --- meta:\n");
	ft_putstr("            sort_size: ");
	ft_putnbr(meta->sort_size);
	ft_putchar('\n');
	ft_putstr("           total_size: ");
	ft_putnbr(meta->total_size);
	ft_putchar('\n');
	ft_putstr("       size_remaining: ");
	ft_putnbr(meta->size_remaining);
	ft_putchar('\n');
	ft_putstr("           chunk_size: ");
	ft_putnbr(meta->chunk_size);
	ft_putchar('\n');
	ft_putstr("           chunk_left: ");
	ft_putnbr(meta->chunk_left);
	ft_putchar('\n');
	ft_putchar('\n');
}

static void		first_pass_bubble(t_state *state, t_meta *meta)
{
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- trying bubble\n\n");
	if (meta->sort_size == 2 && meta->size_remaining >= 2)
		try_rbubble(state, STACK_A, meta->first_pass_map[meta->first_pass_spot]);
	meta->first_pass_spot++;
}

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
	return (0);
}

static int		push_chunk_to_b(t_state *state, t_meta *meta)
{
	if (g_flags & FLAG_VERBOSE)
	{
		ft_putstr("   --- pushing ");
		ft_putnbr(meta->chunk_size);
		ft_putstr(" to the right to be merged\n\n");
	}
	print_meta(meta);
	exec_n_instr(state, PB, meta->chunk_size);
	meta->size_remaining -= meta->chunk_size;
	return (0);
}

static int		init_next_chunk(t_meta *meta)
{
	if (meta->sort_size < meta->size_remaining)
		meta->chunk_size = meta->sort_size;
	else
		meta->chunk_size = meta->size_remaining;
	meta->chunk_left = meta->chunk_size;
	return (0);
}

int				merge_sort(t_state *state)
{
	t_meta		meta;

	UNUSED(&first_pass_bubble);
	meta.sort_size = 2;
	meta.total_size = stack_size(*(state->a));
	meta.first_pass_map = build_order_map(meta.total_size / 2 + 1);
	meta.first_pass_spot = 0;
	while (meta.sort_size < meta.total_size)
	{
		meta.size_remaining = meta.total_size;
		meta.reverse_map = build_order_map(meta.total_size / (meta.sort_size * 2) + 1);
		meta.map_spot = 0;
		while (meta.size_remaining)
		{
			first_pass_bubble(state, &meta);
			init_next_chunk(&meta);
			push_chunk_to_b(state, &meta);
			init_next_chunk(&meta);
			first_pass_bubble(state, &meta);
			merge_chunks(state, &meta);
			goto_end_of_chunk(state, &meta);
			print_meta(&meta);
		}
		meta.sort_size *= 2;
		if (g_flags & FLAG_VERBOSE)
			ft_putstr("   --- --- --- --- --- --- finished sort pass --- --- --- --- --- ---\n\n");
		print_meta(&meta);
		free(meta.reverse_map);
	}
	free(meta.first_pass_map);
	return (0);
}
