/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:07:34 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/14 16:54:57 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (new)
	{
		new->next = NULL;
		if (*alst == NULL)
			(*alst) = new;
		else
		{
			tmp = *alst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

/*void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (*alst == NULL)
	{
		(*alst) = new;
		return ;
	}
	if (new)
	{
		tmp = *alst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		return ;
}
*/
