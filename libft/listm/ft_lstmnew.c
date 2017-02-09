/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 22:21:34 by mburson           #+#    #+#             */
/*   Updated: 2017/01/12 22:21:36 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <string.h>

t_listm		*ft_lstmnew(void *content)
{
	t_listm		*link;

	if (!(link = (t_listm*)malloc(sizeof(t_listm))))
		return (NULL);
	link->content = content;
	link->next = NULL;
	return (link);
}
