/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 22:14:22 by mburson           #+#    #+#             */
/*   Updated: 2017/01/29 22:14:23 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <push_swap.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int		main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**instr;
	_Bool	verbose;

	verbose = false;
	a = NULL;
	b = NULL;
	if (add_arguments(argc, argv, &a, &verbose)
		|| get_instructions(&instr, verbose)
		|| execute_instructions(&a, &b, instr, verbose))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (solve_check(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	free_instructions(&instr);
	return (0);
}
