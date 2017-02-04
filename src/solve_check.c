/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 23:47:08 by mburson           #+#    #+#             */
/*   Updated: 2017/01/29 23:47:10 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		solve_check(t_list *a, t_list *b)
{
	int		last;

	if (b)
		return (0);
	if (!a)
		return (1);
	last = *(int*)(a->content);
	a = a->next;
	while (a)
	{
		if (last > *(int*)(a->content))
			return (0);
		a = a->next;
	}
	return (1);
}
