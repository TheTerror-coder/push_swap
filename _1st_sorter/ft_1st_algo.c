/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1st_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:41:42 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/31 15:30:50 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_1st_sorter.h"

void	ft_sort_small_op(t_vars *v, int *_1st)
{
	while (ft_is_sorted(v->a) == __FALSE || ft_lstsize(v->b))
		ft_alltry(v);
	*_1st = v->count;
	if (!*_1st)
		ft_prcss_exit(v, EXIT_SUCCESS);
}

void	ft_sort_small(t_vars *v, t_bool simple1)
{
	v->count = 0;
	ft_rebuild(v);
	ft_mka_ulst(v);
	if (simple1)
		ft_sort_small_op(v, &v->_1st);
	else
	{
		while (ft_lstsize(v->a) > 3)
			ft_push(v, PB, &v->a, &v->b);
		ft_sort_small_op(v, &v->_1st2);
	}
}
