/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhalf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:26:06 by mburson           #+#    #+#             */
/*   Updated: 2016/12/16 19:26:08 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char		*ft_strsplitf(char **str, char *split)
{
	char	*left;
	char	*right;

	left = ft_strndup(*str, split - *str);
	right = ft_strdup(split + sizeof(char));
	free(*str);
	*str = right;
	return (left);
}
