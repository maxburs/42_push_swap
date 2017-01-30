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

int		main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	add_arguments(**argv, &a);
	execute_instructions(&a, &b);
	if (solve_check(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstdel(&a);
	ft_lstdel(&b);
	return (0);
}
