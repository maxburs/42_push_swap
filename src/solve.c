/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:06:26 by mburson           #+#    #+#             */
/*   Updated: 2017/02/03 20:06:28 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int		solve(t_list **instr, t_list **a, t_list **b)
{
	int		instruction;

	UNUSED(a);
	UNUSED(b);
	instruction = 5;
	ft_lstadd(instr, ft_lstnew(&instruction, sizeof(int)));
	instruction = 1;
	ft_lstadd(instr, ft_lstnew(&instruction, sizeof(int)));
	instruction = 2;
	ft_lstadd(instr, ft_lstnew(&instruction, sizeof(int)));
	instruction = 3;
	ft_lstadd(instr, ft_lstnew(&instruction, sizeof(int)));
	return (0);
}
