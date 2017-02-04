/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:37:37 by mburson           #+#    #+#             */
/*   Updated: 2017/02/03 21:37:39 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdio.h>

/*
** checks to see if the stack only needs rotating to be in order
*/
/*
int		stack_r_order(t_list **stack)
{
	
}
*/

/*
** returns the number of rotate to get to the smallest int
** returns negative if its faster to rotate backwards
*/
int		path_to_smallest(t_list *stack)
{
	int		front;
	int		back;
	int		highscore;

	front = 0;
	back = 0;
	if (!stack)
		return (0);
	highscore = *(int*)(stack->content);
	stack = stack->next;
	while (stack)
	{
		back++;
		if (*(int*)(stack->content) < highscore)
		{
			highscore = *(int*)(stack->content);
			front += back;
			back = 0;
		}
		stack = stack->next;
	}
	back++;
	return (front < back ? front : -1 * back);
}