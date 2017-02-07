/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 01:55:51 by mburson           #+#    #+#             */
/*   Updated: 2017/02/06 01:55:52 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <push_swap.h>

static _Bool	*increase_size(_Bool *map, size_t size)
{
	size_t	i;
	size_t	l;
	_Bool	*map_new;

	if (!(map_new = (_Bool*)malloc(sizeof(_Bool) * (size + 1))))
		return (NULL);
	i = 0;
	l = 0;
	while (l < size)
	{
		if (map[i] == 0)
		{
			map_new[l] = 1;
			map_new[l + 1] = 0;
		}
		else
		{
			map_new[l] = 0;
			map_new[l + 1] = 1;
		}
		i++;
		l += 2;
	}
	return (map_new);
	
}

static int		print_order_map(_Bool *map, size_t size)
{
	size_t	i;

	i = 0;
	if (!(g_flags & FLAG_VERBOSE))
		return (0);
	ft_putstr("   --- order map of size: ");
	if (size > INT_MAX)
		ft_putstr("REAL DAMN HUGE");
	else
		ft_putnbr((int)size);
	ft_putchar('\n');
	while (i < size)
	{
		if (map[i])
			ft_putchar('#');
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
	return (0);
}

_Bool			*build_order_map(size_t size)
{
	_Bool		*map;
	_Bool		*map_old;
	size_t		cur_size;

	cur_size = 1;
	if (!(map = (_Bool*)malloc(sizeof(_Bool))))
		return (NULL);
	*map = 0;
	while (cur_size < size)
	{
		cur_size *= 2;
		map_old = map;
		map = increase_size(map_old, cur_size);
		free(map_old);
		if (!map)
			return (NULL);
	}
	print_order_map(map, cur_size);
	return (map);
}
