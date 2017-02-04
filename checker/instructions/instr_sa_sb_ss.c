/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:40:20 by mburson           #+#    #+#             */
/*   Updated: 2017/01/31 04:40:21 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <checker.h>

static int	lst_swaptop(t_list **list)
{
	t_list	*swap;

	if (!*list || !(*list)->next)
		return (0);
	swap = *list;
	*list = (*list)->next;
	swap->next = (*list)->next;
	(*list)->next = swap;
	return (0);
}

int		exec_sa(t_list **a, t_list **b)
{
	UNUSED(b);
	return (lst_swaptop(a));
}

int		exec_sb(t_list **a, t_list **b)
{
	UNUSED(a);
	return (lst_swaptop(b));
}

int		exec_ss(t_list **a, t_list **b)
{
	if (lst_swaptop(a))
		return (1);
	return (lst_swaptop(b));
}
