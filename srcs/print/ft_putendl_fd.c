/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:37:17 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/13 19:36:10 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return (FAILURE);
	if (write(fd, s, ft_strlen(s)) == FAILURE)
		return (FAILURE);
	return ((int)write(1, "\n", 1));
}
