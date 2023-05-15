/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstalgo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:41:42 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/15 16:12:38 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fst_sorter.h"

void	ft_sort_small(t_vars *v)
{
	v->count = 0;
	ft_rebuild(v);
	while (ft_is_sorted(v->a) == __FALSE || ft_lstsize(v->b))
	{
		ft_try_swap(v, &v->a, &v->b);
		ft_try_push(v, &v->a, &v->b);
	}
	v->fst = v->count;
	if (!v->fst)
		ft_prcss_exit(v, EXIT_SUCCESS);
}
