/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_n_smallest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 22:47:29 by mburson           #+#    #+#             */
/*   Updated: 2017/02/04 22:47:30 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <push_swap.h>

#include <stdio.h>

/*
t_list			**smallest_address(t_list **stack)
{
	int		smallest;
	t_list	**smallest_address;

	smallest = *(int*)(stack->content);
	smallest_address = stack;
	stack = &((*stack)->next);
	while (*stack)
	{
		if (*(int*)((*stack)->content) < smallest)
		{
			smallest = *(int*)(stack->content);
			smallest_address = stack;
		}
		stack = &((*stack)->next);
	}
	return (smallest_address);
}
*/

/*
t_list			**lst_contains(t_list **stack, int find_me)
{
	while (*stack)
	{
		if (*(int*)((*stack)->content) == find_me)
		{
			return (stack);
		}
		stack = &((*stack)->next);
	}
	return (NULL);
}
*/

static int		*biggest_address(t_list *stack)
{
	int		*biggest;

	biggest = (int*)(stack->content);
	stack = stack->next;
	while (stack)
	{
		if (*(int*)(stack->content) > *biggest)
		{
			biggest = (int*)(stack->content);
		}
		stack = stack->next;
	}
	return (biggest);
}

/*
** returns a linked list containing the
**     n smallest numbers in the given linked list
*/

t_list			*find_n_smallest(t_list *stack, int n)
{
	t_list	*smallest;
	int		*biggest;

	if (!stack)
		return (NULL);
	smallest = NULL;
	while (n)
	{
		if (stack)
			ft_lstadd(&smallest, ft_lstnew(stack->content, stack->content_size));
		else
		{
			free_stack(&smallest);
			return (NULL);
		}
		stack = stack->next;
		n--;
	}
	biggest = biggest_address(smallest);
	while (stack)
	{
		if (*(int*)(stack->content) < *biggest)
		{
			*biggest = *(int*)(stack->content);
			biggest = biggest_address(smallest);
		}
		stack = stack->next;
	}
	return (smallest);
}

int			nth_smallest(t_list *stack, int n)
{
	t_list	*smallest;
	int		biggest_smallest;

	smallest = find_n_smallest(stack, n);
	//ft_putstr("smallest found: ");
	//print_stack(smallest);
	//ft_putchar('\n');
	biggest_smallest = find_biggest(smallest);
	free_stack(&smallest);
	return (biggest_smallest);
}
