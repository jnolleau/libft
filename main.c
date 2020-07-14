/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 19:16:50 by julien            #+#    #+#             */
/*   Updated: 2020/07/14 12:18:58 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	size_t	len;
	char	*dst;

	if (argc == 2)
	{	
		len = ft_strlen(argv[1]);
		dst = ft_calloc((len + 1), 1);
		if (dst)
		{
			dst = ft_memcpy(dst, argv[1], len + 1);
			ft_putendl(dst);
			printf("len src:%zu len dst:%zu\n", len, ft_strlen(dst));
			free(dst);
		}
	}
	return (0);
}
