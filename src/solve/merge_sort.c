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

int				merge_sort(t_state *state)
{
	int			sort_size;
	int			total_size;
	int			size_remaining;
	int			i;

	sort_size = 2;
	total_size = stack_size(*(state->a));
	//while (total_size > sort_size)
	while (sort_size == 2)
	{
		size_remaining = total_size;
		while (size_remaining)
		{
			if (sort_size == 2
				&& *(int*)((*(state->a))->content) > *(int*)(((*(state->a))->next)->content))
				exec_instr(state, SA);
			if (g_flags & FLAG_VERBOSE)
			{
				ft_putstr("   --- starting merge step\n\n");
			}
			if (g_flags & FLAG_VERBOSE)
			{
				ft_putstr("   --- pushing ");
				ft_putnbr(sort_size < size_remaining ? sort_size : size_remaining);
				ft_putstr(" to the right to be merged\n\n");
			}
			exec_n_instr(state, PB, sort_size < size_remaining ? sort_size : size_remaining);
			size_remaining -= sort_size;
			if (sort_size == 2
				&& *(int*)((*(state->a))->content) > *(int*)(((*(state->a))->next)->content))
				exec_instr(state, SA);
			if (g_flags & FLAG_VERBOSE)
				ft_putstr("   --- incrementing past chunk\n\n");
			i = 0;
			while (size_remaining && i < sort_size)
			{
				exec_instr(state, RA);
				size_remaining--;
				i++;	
			}
			if (g_flags & FLAG_VERBOSE)
				ft_putstr("   --- merging\n\n");
			while (size_remaining && i)
			{
				while ( *(state->b) && (*(int*)((*(state->b))->content) >= *(int*)((ft_lst_last(*(state->a)))->content)))
				{
					exec_instr(state, PA);
					size_remaining++;
				}
				exec_instr(state, RRA);
				size_remaining++;
				i--;
			}
			while (*(state->b))
			{
				exec_instr(state, PA);
				exec_instr(state, RRA);
				size_remaining++;
			}
			if (g_flags & FLAG_VERBOSE)
				ft_putstr("   --- incrementing past chunk\n\n");
			while (size_remaining && i < sort_size * 2)
			{
				exec_instr(state, RA);
				size_remaining--;
				i++;
			}
		}
		sort_size *= 2;
		if (g_flags & FLAG_VERBOSE)
		{
			ft_putstr("   --- finished sort pass\n\n");
		}
	}
	return (0);
}
