/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 22:11:49 by mburson           #+#    #+#             */
/*   Updated: 2017/01/12 22:11:50 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstmadd_b(t_listm **start, void *content)
{
	t_listm		*link;

	if (!*start)
	{
		*start = ft_lstmnew(content);
		return ;
	}
	link = (*start);
	while (link->next)
		link = link->next;
	link->next = ft_lstmnew(content);
}
