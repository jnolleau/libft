/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:03:20 by julnolle          #+#    #+#             */
/*   Updated: 2020/07/29 15:04:11 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*tab_to_list(char **tab)
{
	t_list	*list;
	size_t	i;

	i = 0;
	list = NULL;
	while (tab[i])
	{
		ft_lstadd_back(&list, ft_lstnew(ft_strdup(tab[i])));
		i++;
	}
	return (list);
}
