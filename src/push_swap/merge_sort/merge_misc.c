/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_verbose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:19:12 by mburson           #+#    #+#             */
/*   Updated: 2017/02/06 19:19:14 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

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

/*
** instead of going through the list with a sort size of
**    two creating size_remaining 4 chunks durring the
**    first pass we swap any pairs to two out of order
*/

void			merge_bubble(t_state *state, t_meta *meta)
{
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- trying bubble\n\n");
	if (meta->sort_size == 2 && meta->size_remaining >= 2)
		try_rbubble(state, STACK_A,
			meta->bubble_map[meta->bubble_index]);
	meta->bubble_index++;
}

/*
** pushes the next chunk to stack b
*/

int				merge_chunk_to_b(t_state *state, t_meta *meta)
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
