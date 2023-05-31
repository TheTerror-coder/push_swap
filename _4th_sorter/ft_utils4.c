/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:19:45 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/31 15:33:17 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_4th_sorter.h"

void	ft_looppusha(t_vars *v)
{
	while (ft_lstsize(v->b))
		ft_push(v, PA, &v->a, &v->b);
}

void	ft_init4thtools(t_vars *v)
{
	v->vinf = 0;
	v->vsup = (v->len / v->chunks);
	v->holded = -1;
	v->hold_st = -1;
	v->hold_nd = -1;
	if (v->chunks > v->len)
		ft_prcss_exit(v, EXIT_FAILURE);
}
