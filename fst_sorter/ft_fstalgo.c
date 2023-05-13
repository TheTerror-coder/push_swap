/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstalgo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:41:42 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/13 22:46:45 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fst_sorter.h"

void	ft_sort_small(t_vars *v)
{
	while (ft_is_sorted(v->a) == __FALSE || ft_lstsize(v->b))
	{
		ft_try_swap(&v->a, &v->b);
		ft_try_push(&v->a, &v->b);
	}
}
