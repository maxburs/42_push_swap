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

int		exec_sa(t_list **a, t_list **b)
{
	t_list	*swap;

	if (!*a || !(*a)->next)
		return (0);
	swap = *a;
	*a = (*a)->next;
	swap->next = (*a)->next;
	(*a)->next = swap;
	print_stacks(*a, *b);
	return (0);
}
