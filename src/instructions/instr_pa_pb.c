/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_pa_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:16:58 by mburson           #+#    #+#             */
/*   Updated: 2017/02/03 15:17:00 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static int		lst_movetop(t_list **from, t_list **to)
{
	t_list	*swap;

	if (!*from)
		return (0);
	swap = *from;
	*from = (*from)->next;
	swap->next = *to;
	*to = swap;
	return (0);
}

int		exec_pa(t_list **a, t_list **b)
{
	return (lst_movetop(b, a));
}

int		exec_pb(t_list **a, t_list **b)
{
	return (lst_movetop(a, b));
}
