/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_ra_rb_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:30:05 by mburson           #+#    #+#             */
/*   Updated: 2017/02/03 15:30:07 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <string.h>

/*
** remove the first element of a list a return it;
*/

static t_list	*lst_shift(t_list **list)
{
	t_list	*swap;

	if (!*list)
		return (NULL);
	swap = *list;
	*list = (*list)->next;
	swap->next = NULL;
	return (swap);
}

/*
** first element becomes the last one;
*/

static int		lst_rotate(t_list **list)
{
	t_list	*swap;
	t_list	*track;

	if (!*list || !(*list)->next)
		return (0);
	swap = lst_shift(list);
	track = *list;
	while (track->next)
	{
		track = track->next;
	}
	track->next = swap;
	return (0);
}

int				exec_ra(t_list **a, t_list **b)
{
	UNUSED(b);
	return (lst_rotate(a));
}

int				exec_rb(t_list **a, t_list **b)
{
	UNUSED(a);
	return (lst_rotate(b));
}

int				exec_rr(t_list **a, t_list **b)
{
	if (lst_rotate(a))
		return (1);
	return (lst_rotate(b));
}
