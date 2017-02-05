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

int		stack_in_order(t_list *stack)
{
	int		last;

	if (!stack)
		return (1);
	last = *(int*)(stack->content);
	stack = stack->next;
	while (stack)
	{
		if (last > *(int*)(stack->content))
			return (0);
		last = *(int*)(stack->content);
		stack = stack->next;
	}
	return (1);
}


int		solve_check(t_list *a, t_list *b)
{
	if (b)
		return (0);
	return (stack_in_order(a));
}

