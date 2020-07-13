/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:11:25 by julnolle          #+#    #+#             */
/*   Updated: 2020/07/13 11:41:16 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst != NULL && *lst != NULL && (*del) != NULL)
	{
		while (*lst)
		{
			del((*lst)->content);
			(*lst) = (*lst)->next;
		}
		free(*lst);
		*lst = NULL;
	}
}
