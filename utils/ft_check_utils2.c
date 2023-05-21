/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:08:58 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/19 19:04:01 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_assert	ft_cmp_content(t_list *elm1, t_list *elm2)
{
	if (!elm1 || !elm2)
		return (__NULL);
	if (*((int *) elm1->content) == *((int *) elm2->content))
		return (EQUAL);
	if (*((int *) elm1->content) > *((int *) elm2->content))
		return (SUPERIOR);
	if (*((int *) elm1->content) < *((int *) elm2->content))
		return (INFERIOR);
	return (0);
}

t_bool	ft_is_sorted(t_list *lst)
{
	if (!lst)
		return (__NULL);
	while (lst && lst->next)
	{
		if (ft_cmp_content(lst, lst->next) == SUPERIOR)
			return (__FALSE);
		lst = lst->next;
	}
	return (__TRUE);
}

t_bool	ft_rev_sorted(t_list *lst)
{
	if (!lst)
		return (__NULL);
	while (lst && lst->next)
	{
		if (ft_cmp_content(lst, lst->next) == INFERIOR)
			return (__FALSE);
		lst = lst->next;
	}
	return (__TRUE);
}

t_bool	ft_is_smallest(t_list *elm, t_list *lst)
{
	if (!lst || !elm)
		return (__NULL);
	while (lst)
	{
		if (ft_cmp_content(elm, lst) == SUPERIOR)
			return (__FALSE);
		lst = lst->next;
	}
	return (__TRUE);
}

t_bool	ft_is_biggest(t_list *elm, t_list *lst)
{
	if (!lst || !elm)
		return (__NULL);
	while (lst && lst != elm)
	{
		if (ft_cmp_content(elm, lst) == INFERIOR)
			return (__FALSE);
		lst = lst->next;
	}
	return (__TRUE);
}
