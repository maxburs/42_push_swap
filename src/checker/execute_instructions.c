/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 23:47:17 by mburson           #+#    #+#             */
/*   Updated: 2017/01/29 23:47:18 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <push_swap.h>
#include <stdbool.h>

static void		invalid_operation(char *operation, _Bool verbose)
{
	if (verbose == false)
		return ;
	ft_putstr_fd("invalid operation: ->", 2);
	ft_putstr_fd(operation, 2);
	ft_putstr_fd("<-\n\n", 2);
}

int				execute_instructions(t_state *state, t_list **a,
											t_list **b, char **instr)
{
	int		i;

	if (state->verbose)
		ft_putchar('\n');
	while (*instr)
	{
		i = 0;
		while (state->op[i])
		{
			if (ft_strequ(*instr, state->op[i]))
			{
				(*state->op_func[i])(a, b);
				print_instr_res(a, b, *instr, state->verbose);
				break ;
			}
			i++;
		}
		if (!state->op[i])
			invalid_operation(*instr, state->verbose);
		instr++;
	}
	return (0);
}
