/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 23:51:44 by mburson           #+#    #+#             */
/*   Updated: 2017/01/29 23:51:45 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			print_stack(t_list *stack)
{
	while (stack)
	{
		ft_putnbr(*(int*)(stack->content));
		stack = stack->next;
		if (stack)
			ft_putstr(", ");
	}
	ft_putchar('\n');
}

void			print_stacks(t_list *a, t_list *b)
{
	ft_putstr("a: ");
	print_stack(a);
	ft_putstr("b: ");
	print_stack(b);
	ft_putchar('\n');
}

void			print_starting_stack(t_list *stack)
{
	ft_putstr("starting stack: ");
	print_stack(stack);
}

void			print_instructions(char **instr)
{
	int 	i;

	ft_putstr("operations: ");
	i = 0;
	while (instr[i])
	{
		ft_putstr(instr[i]);
		i++;
		if (instr[i])
			ft_putstr(", ");
	}
	ft_putchar('\n');
}

void			print_instr_res(t_list **a, t_list **b, char const *instr)
{
	ft_putstr("operation: ");
	ft_putstr(instr);
	ft_putstr("\n");
	print_stacks(*a, *b);
}
