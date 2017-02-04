/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rra_rrb_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:29:17 by mburson           #+#    #+#             */
/*   Updated: 2017/02/03 15:29:19 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <string.h>

/*
** remove the last element of a list a return it;
*/

static t_list	*lst_pop(t_list **list)
{
	t_list	*swap;

	if (!list)
		return (NULL);
	while ((*list)->next)
	{
		list = &((*list)->next);
	}
	swap = *list;
	*list = NULL;
	return (swap);
}

/*
** last element becomes the first one;
*/

static int	lst_rrotate(t_list **list)
{
	t_list	*swap;

	if (!*list)
		return (0);
	swap = lst_pop(list);
	if (*list)
		swap->next = (*list);
	*list = swap;
	return (0);
}


int		exec_rra(t_list **a, t_list **b)
{
	UNUSED(b);
	return (lst_rrotate(a));
}

int		exec_rrb(t_list **a, t_list **b)
{
	UNUSED(a);
	return (lst_rrotate(b));
}

int		exec_rrr(t_list **a, t_list **b)
{
	if (lst_rrotate(a))
		return (1);
	return (lst_rrotate(b));
}
