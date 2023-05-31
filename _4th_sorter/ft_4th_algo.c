/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4th_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:44:56 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/31 13:09:32 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_4th_sorter.h"

t_bool	ft_sethold(t_vars *v);
void	ft_looppusha(t_vars *v);
void	ft_init4thtools(t_vars *v);
void	ft_readya(t_vars *v);
void	ft_readyb(t_vars *v);
void	ft_drivebig_up(t_vars *v);
void	ft_sort_bigtwo_op(t_vars *v);

void	ft_sort_bigtwo(t_vars *v)
{
	int	i;
	int	chunk;
	int	chstep;

	i = -2;
	v->_4th = __INT_MAX;
	if (v->len < 250)
		chstep = 5;
	else
		chstep = 11;
	while (!v->final && i < 3)
	{
		v->chunks = chstep + i;
		ft_sort_bigtwo_op(v);
		if (v->count < v->_4th)
		{
			chunk = v->chunks;
			v->_4th = v->count;
		}
		i++;
		v->chunks = chunk;
	}
	ft_sort_bigtwo_op(v);
}

void	ft_sort_bigtwo_op(t_vars *v)
{
	v->count = 0;
	ft_rebuild(v);
	ft_mka_ulst(v);
	ft_init4thtools(v);
	while (ft_lstsize(v->a))
	{
		if (ft_lstsize(v->a) > 1)
		{
			ft_sethold(v);
			ft_readya(v);
		}
		else
			v->val = *((int *) v->a->content);
		if (ft_lstsize(v->b) > 1)
			ft_readyb(v);
		ft_push(v, PB, &v->a, &v->b);
	}
	if (!ft_is_biggest(v->b, v->b))
		ft_drivebig_up(v);
	if (ft_rev_sorted(v->b))
		ft_looppusha(v);
	else
		ft_prcss_exit(v, EXIT_FAILURE);
}
