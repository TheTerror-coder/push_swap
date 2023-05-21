/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1st_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:41:42 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/17 12:50:34 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_1st_sorter.h"

void	ft_sort_small(t_vars *v)
{
	v->count = 0;
	ft_rebuild(v);
	while (ft_is_sorted(v->a) == __FALSE || ft_lstsize(v->b))
		ft_alltry(v);
	v->_1st = v->count;
	if (!v->_1st)
		ft_prcss_exit(v, EXIT_SUCCESS);
}
