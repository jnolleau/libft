/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_by_key.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:19:56 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/14 16:53:08 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
t_list	*sort_list_by_key(t_list *env)
{
	t_list		*sorted_env;
	t_key_val	*new;
	char		**env_tab;
	char		**elem;
	size_t		i;

	env_tab = ft_list_to_tab(env);
	ft_n_sort_string_tab(env_tab, '=');
	i = 0;
	sorted_env = NULL;
	while(env_tab[i])
	{
		elem = ft_split_env(env_tab[i]);
		new = malloc(sizeof(t_key_val));
		new->key = elem[0];
		new->val = elem[1];
		ft_lstadd_back(&sorted_env, ft_lstnew(new));
		free(elem);
		i++;
	}
	free_tab2(env_tab);
	return (sorted_env);
}
*/
