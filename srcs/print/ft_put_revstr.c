/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_revstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:40:15 by julnolle          #+#    #+#             */
/*   Updated: 2021/08/18 14:51:51 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_revstr(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	while (len-- > 0)
		ft_putchar(str[len]);
}
