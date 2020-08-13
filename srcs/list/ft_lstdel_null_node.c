/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_null_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:08:40 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/06 11:17:39 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Not checked yet
void	lst_del_null_nodes(t_list **list, void (*del)(t_list *))
{
	t_list		*tmp;
	t_list		*before;
	int			i;

	before = *list;
	tmp = *list;
	i = 0;
	while (tmp)
	{
		if (tmp->content == NULL)
		{
			if (i == 0)
			{
				before = tmp->next;
				*list = before;
			}
			else
				before->next = tmp->next;
			del(&tmp);
			return ;
		}
		i++;
		before = tmp;
		tmp = tmp->next;
	}
}
