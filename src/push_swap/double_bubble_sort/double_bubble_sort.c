/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_bubble_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:55:26 by mburson           #+#    #+#             */
/*   Updated: 2017/02/06 20:55:27 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static int		select_right_numbers(t_state *state, t_list **goes_right)
{
	t_list	*stack;

	stack = *stack_of_type(state, STACK_A);
	*goes_right = find_n_smallest(stack, lst_size(stack) / 2);
	return (0);
}

int				double_bubble_sort(t_state *state)
{
	t_list	*goes_right;

	select_right_numbers(state, &goes_right);
	ft_putstr("these go right: ");
	print_stack(goes_right);
	return (0);
}