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

static int		in_order(t_meta *meta)
{
	return (!meta->reverse_map[meta->map_spot]);
}

int				merge_chunks(t_state *state, t_meta *meta)
{
	if (g_flags & FLAG_VERBOSE)
	{
		ft_putstr("   --- merging\n");
		if (in_order(meta))
			ft_putstr("         chunk is being sorted IN ORDER\n\n");
		else
			ft_putstr("         chunk is being sorted IN REVERSE\n\n");
	}
	print_meta(meta);
	while (meta->chunk_left > 0 && *(state->b))
	{
		if ((in_order(meta) && top_of_stack(state, STACK_A) >= top_of_stack(state, STACK_B))
			|| (!in_order(meta) && top_of_stack(state, STACK_A) <= top_of_stack(state, STACK_B)))
		{
			if (g_flags & FLAG_VERBOSE)
				ft_putstr("   --- stack b first\n");
			exec_instr(state, PA);
			exec_instr(state, RA);
			meta->chunk_size++;
		}
		else
		{
			if (g_flags & FLAG_VERBOSE)
				ft_putstr("   --- stack a first\n");
			exec_instr(state, RA);
			meta->size_remaining--;
			meta->chunk_left--;
		}
	}
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- nothing left in chunk, moving rest of stack b\n\n");
	while (*(state->b))
	{
		exec_instr(state, PA);
		exec_instr(state, RA);
		meta->chunk_size++;
	}
	meta->map_spot++;
	return (0);
}