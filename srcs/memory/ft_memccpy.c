/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:24:56 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/14 16:54:23 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_cpy;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		if (((unsigned char *)dst)[i] == (unsigned char)c)
		{
			dst_cpy = (unsigned char *)dst + i + 1;
			return ((void *)dst_cpy);
		}
		i++;
	}
	return (NULL);
}
