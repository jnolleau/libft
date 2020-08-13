/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:51:52 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/13 16:29:58 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_base(char *str)
{
	size_t i;
	size_t j;
	size_t count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[j] != 0)
		{
			if (str[j] == str[i])
				count++;
			j++;
		}
		if (str[i] == '+' || str[i] == '-')
			count++;
		i++;
	}
	if (i == 0 || i == 1 || count != ft_strlen(str))
		return (0);
	else
		return (1);
}

void	convert_base(int nbr, char *base)
{
	long int div;
	long int mod;
	long int nb;

	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	mod = nb % ft_strlen(base);
	div = nb / ft_strlen(base);
	if (div >= 1)
		convert_base(div, base);
	ft_putchar(base[mod]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (check_base(base) == 1)
		convert_base(nbr, base);
}
