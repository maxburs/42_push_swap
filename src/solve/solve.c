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
#include <stdbool.h>

#include <stdio.h>

static int		exec_instr(t_state *state, int instr)
{
	if ((*g_func[instr])(state->a, state->b))
		return (1);
	ft_lstbadd(state->instr, ft_lstnew(&instr, sizeof(int)));
	if (g_flags & FLAG_VERBOSE)
		print_instr_res(state->a, state->b, g_instr[instr]);
	return (0);
}
/*
static int		exec_n_instr(t_state *state, int instr, int n)
{
	while (n)
	{
		if (exec_instr(state, instr))
			return (1);
		n--;
	}
	return (0);
}
*/
/*
** moves a stack to the smallest integer in it
** bubble sorting along the way
*/
static int		goto_smallest_bubble(t_state *state, int is_a)
{
	int		path;
	int		smallest;
	t_list	**stack;
	int		bubble;
	int		move;
	int		biggest;

	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- starting: goto_smallest_bubble ---\n\n");
	stack = is_a ? state->a : state->b;
	path = path_to_smallest(*stack);
	smallest = find_smallest(*stack);
	biggest = find_biggest(*stack);
	bubble = is_a ? SA : SB;
	move = (path > 0) ? (is_a ? RA : RB) : (is_a ? RRA : RRB);
	while (*(int*)((*stack)->content) != smallest)
	{
		if (*(int*)((*stack)->content) > *(int*)(((*stack)->next)->content)
			&& (*(int*)((*stack)->content) != biggest)
			&& (*(int*)(((*stack)->next)->content) != smallest))
			exec_instr(state, bubble);
		else
			exec_instr(state, move);
	}
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("   --- ending: goto_smallest_bubble ---\n\n");
	return (0);
}

int				solve(t_list **instr, t_list **a, t_list **b)
{
	t_state		state;

	state.instr = instr;
	state.a = a;
	state.b = b;
	while (*a)
	{
		goto_smallest_bubble(&state, true);
		if (stack_in_order(*a))
		{
			if (g_flags & FLAG_VERBOSE)
				ft_putstr("   --- stack 'a' in order, finalizing... ---\n\n");
			break ;
		}
		exec_instr(&state, PB);
	}
	while (*b)
		exec_instr(&state, PA);
	return (0);
}
