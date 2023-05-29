/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2nd_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:58:35 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/22 14:47:45 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2nd_sorter.h"

void	ft_2ndtryout(t_vars *v);
void	ft_set_mxbit(t_vars *v);
int		ft_nthbit(int *content, int nth);

void	ft_sort_bigone(t_vars *v)
{
	int	i;

	v->nth = 0;
	v->count = 0;
	ft_rebuild(v);
	ft_mka_ulst(v);
	ft_set_mxbit(v);
	while (!ft_is_sorted(v->a) || ft_lstsize(v->b))
	{
		i = 0;
		while (i < v->len)
		{
			ft_2ndtryout(v);
			i++;
		}
		while (ft_lstsize(v->b))
			ft_push(v, PA, &v->a, &v->b);
		v->nth++;
		if (v->nth >= v->max_bit)
			v->nth = 0;
	}
	v->_2nd = v->count;
}

void	ft_2ndtryout(t_vars *v)
{
	if (!ft_nthbit(v->a->content, v->nth))
		ft_push(v, PB, &v->a, &v->b);
	else
		ft_rotate(v, RA, &v->a, &v->b);
}

// t_list	*a;
// if (v->nth == v->max_bit - 2)
// {

// a = v->a;
// while (a)
// {
// 	ft_putnbr_fd(*((int *) a->content), 1);
// ft_putendl_fd("", 1);
// 	a = a->next;
// }
// ft_prcss_exit(v, EXIT_FAILURE);
// }