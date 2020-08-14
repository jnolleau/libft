/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 19:16:50 by julien            #+#    #+#             */
/*   Updated: 2020/08/14 18:41:47 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	i = 1;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret != -1)
			ft_putendl(line);
		i++;
		free(line);
	}
	if (argc == 2)
		close(fd);
	// system("leaks a.out");
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
