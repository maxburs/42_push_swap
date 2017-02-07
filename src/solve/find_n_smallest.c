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
#include <limits.h>

static int		*biggest_address(t_list *stack)
{
	int		*biggest;

	if (!stack)
		return (NULL);
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

static int		clone_n_links(t_list *src, t_list **dst, int n)
{
	while (n)
	{
		if (src)
			ft_lstadd(dst, ft_lstnew(src->content, src->content_size));
		else
		{
			free_stack(dst);
			return (1);
		}
		src = src->next;
		n--;
	}
	return (0);
}

t_list			*find_n_smallest(t_list *stack, int n)
{
	t_list	*smallest;
	int		*biggest;

	if (!stack)
		return (NULL);
	smallest = NULL;
	if (clone_n_links(stack, &smallest, n))
		return (NULL);
	if (!(biggest = biggest_address(smallest)))
		return (NULL);
	while (n)
	{
		stack = stack->next;
		n--;
	}
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

int				nth_smallest(t_list *stack, int n)
{
	t_list	*smallest;
	int		biggest_smallest;

	smallest = find_n_smallest(stack, n);
	biggest_smallest = find_biggest_old(smallest);
	free_stack(&smallest);
	return (biggest_smallest);
}
