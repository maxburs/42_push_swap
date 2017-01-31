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
#include <checker.h>
#include <unistd.h>
#include <stdlib.h>

int		g_flags;

void	del_num(void *ptr, size_t size)
{
	size++;
	free(ptr);
}

int		main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**instr;

	g_flags = 0;
	a = NULL;
	b = NULL;
	if (add_arguments(argc, argv, &a))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (g_flags & FLAG_VERBOSE)
		print_stack(a);
	get_instructions(&instr);
	if (g_flags & FLAG_VERBOSE)
		print_instructions(instr);
	//execute_instructions(a, b, instr);
	if (solve_check(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (a)
		ft_lstdel(&a, &del_num);
	if (b)
		ft_lstdel(&b, &del_num);
	return (0);
}
