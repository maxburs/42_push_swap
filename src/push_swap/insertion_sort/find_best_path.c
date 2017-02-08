/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:45:53 by mburson           #+#    #+#             */
/*   Updated: 2017/02/07 17:45:54 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#include <stdio.h>

static void		where_to_insert(t_list *stack, int insert_me, int *forward_path,
								int *backwards_path)
{
	int		front;
	int		back;

	front = 0;
	back = 0;

	if (!stack
		|| (insert_me >= *(int*)(stack->content)
			&& insert_me >= *(int*)(ft_lst_last(stack)->content))
		|| (insert_me < *(int*)(stack->content)
			&& insert_me < *(int*)(ft_lst_last(stack)->content)))
	{
		printf("test2\n");
		*forward_path = 0;
		*backwards_path = 0;
		return ;
	}
	while ((stack->next)
			&& !(*(int*)(stack->content) >= insert_me
			&& *(int*)((stack->next)->content) <= insert_me))
	{
		printf("test3\n");
		front++;
		stack = stack->next;
	}
	while (stack->next)
	{
		printf("test5\n");
		back++;
		stack = stack->next;
	}
	printf("test4\n");
	front++;
	*forward_path = front;
	*backwards_path = back;
}

int				find_best_insert(t_state, int &a_path, int &b_path)
{
	t_list	*stack_a;
	int		best_a;
	int		best b;

	int		a_front;
	int		a_back;
	int		b_font;
	int		b_back;

	stack_a = *stack_of_type(state, STACK_A);
	a_back = lst_size(stack_a);
	while (stack_a)
	{
		where_to_insert(stack_of_type(STACK_B), *(int*)(stack->content),
							&b_front, &b_back);

		a_front++;
		a_back--;
		stack_a = stack_a->next;
	}
}

