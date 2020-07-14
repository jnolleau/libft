/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:21:49 by julnolle          #+#    #+#             */
/*   Updated: 2020/07/14 12:17:55 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*dest;

	dest = NULL;
	dest = (unsigned char *)malloc(size * count);
	if (dest)
		ft_bzero(dest, count * size);
	return ((void *)dest);
}
