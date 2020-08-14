/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 19:16:50 by julien            #+#    #+#             */
/*   Updated: 2020/08/14 16:56:14 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*src;
	char	*ret;
	char	*src2;
	char	*ret2;

	src = ft_strdup("Bonjour");
	ret = ft_strrchr(src, 'j');
	printf("My function\nret: %s\nsrc: %s\n\n", ret, src);

	src2 = ft_strdup("Bonjour");
	ret2 = strrchr(src2, 'j');
	printf("Real function\nret: %s\nsrc: %s\n", ret2, src2);
	free(src);
	free(src2);
	return (0);
}

/*int main(int argc, char const *argv[])
{
	size_t	len;
	char	*s1;
	char	*s2;

	if (argc == 3)
	{
		len = ft_strlen(argv[1]);
		s1 = ft_calloc((len + 1), 1);
		if (s1)
		{
			s1 = ft_memcpy(s1, argv[1], len + 1);
		}
		len = ft_strlen(argv[2]);
		s2 = ft_calloc((len + 1), 1);
		if (s2)
		{
			s2 = ft_memcpy(s2, argv[2], len + 1);
		}
		printf("cmp: %d\n", ft_strcmp(s1, s2));
		free(s1);
		free(s2);
	}
	return (0);
}*/
