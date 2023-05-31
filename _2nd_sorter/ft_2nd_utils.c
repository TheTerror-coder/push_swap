/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2nd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:49:48 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/31 15:31:44 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2nd_sorter.h"

void	ft_set_mxbit(t_vars *v)
{
	int		i;
	int		val;
	int		vsup;
	t_list	*a;

	a = v->a;
	i = 0;
	val = 0;
	vsup = 0;
	while (a)
	{
		vsup = *((int *) a->content);
		if (i == 0)
			val = *((int *) a->content);
		else if (vsup > val)
			val = vsup;
		i++;
		a = a->next;
	}
	i = 0;
	while (val >> i)
		i++;
	v->max_bit = i;
}

int	ft_nthbit(int *content, int nth)
{
	int	n;
	int	x;

	n = *content;
	x = n >> nth;
	return (x & 1);
}

int	ft_zeroat(t_list *lst, int nth)
{
	while (lst)
	{
		if (!ft_nthbit(lst->content, nth))
			return (__TRUE);
		lst = lst->next;
	}
	return (__FALSE);
}
