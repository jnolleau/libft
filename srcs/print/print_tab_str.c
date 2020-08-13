/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:37:25 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/13 17:03:05 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_tab_str(char **tab)
{
	int ret;

	ret = 0;
	if (!tab)
		return (0);
	while (*tab)
		ret = ft_putendl(*tab++);
	return (ret);
}
