/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:47:04 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/13 17:06:05 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl(char const *s)
{
	if (!s)
		return (FAILURE);
	if (write(1, s, ft_strlen(s)) == FAILURE)
		return (FAILURE);
	return ((int)write(1, "\n", 1));
}
