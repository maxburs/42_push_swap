/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnum.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 22:47:32 by mburson           #+#    #+#             */
/*   Updated: 2017/01/29 22:47:33 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <limits.h>
#include <stdbool.h>

static int		lst_contains(t_list *list, int num, _Bool verbose)
{
	while (list)
	{
		if (*(int*)(list->content) == num)
		{
			if (verbose)
			{
				ft_putstr("duplicate input: ");
				ft_putnbr(num);
				ft_putchar('\n');
			}
			return (1);
		}
		list = list->next;
	}
	return (0);
}

static int		parse_arg(char *arg, int *response)
{
	int			num;
	int			is_neg;

	num = 0;
	is_neg = 1;
	if (!arg)
		return (1);
	if (*arg == '-')
	{
		is_neg = -1;
		arg++;
	}
	while ('0' <= *arg && *arg <= '9')
	{
		num *= 10;
		num += is_neg * (*arg - '0');
		arg++;
		if ((is_neg == 1 && num < 0) || (is_neg == -1 && num > 0))
			return (1);
	}
	if (*arg != '\0')
		return (1);
	*response = num;
	return (0);
}

static int		add_arg_array(t_list **stack, char *argv, _Bool *verbose)
{
	char	**split;
	int		i;
	int		argument;

	split = ft_strsplit(argv, ' ');
	i = 0;
	while (split[i])
		i++;
	while (i)
	{
		i--;
		if (parse_arg(split[i], &argument)
			|| lst_contains(*stack, argument, *verbose))
		{
			free_instructions(&split);
			return (1);
		}
		ft_lstadd(stack, ft_lstnew(&argument, sizeof(int)));
	}
	free_instructions(&split);
	return (0);
}

/*
** adds arguments in reverse order,
** not including the zero-ith argument, the filename
*/

int				add_arguments(int argc, char **argv, t_list **stack,
						_Bool *verbose)
{
	while (--argc)
	{
		if (ft_strequ(argv[argc], "-v"))
		{
			*verbose = true;
		}
		else
		{
			if (add_arg_array(stack, argv[argc], verbose))
				return (1);
		}
	}
	if (*verbose)
		print_starting_stack(*stack, verbose);
	return (0);
}
