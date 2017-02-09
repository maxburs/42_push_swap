/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 22:14:14 by mburson           #+#    #+#             */
/*   Updated: 2017/01/29 22:14:15 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

static int		print_lst_instr(t_state *state, t_list *instr, _Bool verbose)
{
	while (instr)
	{
		if (instr->content)
			ft_putstr(state->op[*(int*)(instr->content)]);
		else
		{
			if (verbose)
				ft_putstr_fd("instruction parse error", 2);
			return (1);
		}
		instr = instr->next;
		ft_putchar('\n');
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_list		*instr;
	t_list		*a;
	t_list		*b;
	t_state		state;

	state.instr = &instr;
	state.a = &a;
	state.b = &b;
	state.verbose = false;
	instr = NULL;
	a = NULL;
	b = NULL;
	init_instr(&state);
	if (add_arguments(argc, argv, &a, &state.verbose)
		|| solve(&state)
		|| print_lst_instr(&state, instr, state.verbose))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	free_stack(&instr);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
