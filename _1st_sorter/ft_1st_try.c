/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1st_try.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:48:16 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/15 15:26:35 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_1st_sorter.h"

void	ft_try_rotate(t_vars *v, t_list **a, t_list **b);
void	ft_try_rev_rotate(t_vars *v, t_list **a, t_list **b);

void	ft_try_swap(t_vars *v, t_list **a, t_list **b)
{
	ft_try_rev_rotate(v, a, b);
	ft_try_rotate(v, a, b);
	if (*a && ft_cmp_content(*a, (*a)->next) == SUPERIOR && \
	*b && ft_cmp_content(*b, (*b)->next) == INFERIOR)
		ft_swap(v, SS, a, b);
	else if (*a && ft_cmp_content(*a, (*a)->next) == SUPERIOR)
		ft_swap(v, SA, a, b);
	else if (*b && ft_cmp_content(*b, (*b)->next) == INFERIOR)
		ft_swap(v, SB, a, b);
}

void	ft_try_push(t_vars *v, t_list **a, t_list **b)
{
	if (*a && ft_cmp_content(*a, (*a)->next) == INFERIOR && \
	ft_is_sorted((*a)->next) == __FALSE)
	{
		ft_push(v, PB, a, b);
		return ;
	}
	if (ft_is_sorted(*a) == __TRUE)
	{
		if (ft_rev_sorted(*b) == __TRUE)
		{
			while (*b)
				ft_push(v, PA, a, b);
		}
		else if (*b)
			ft_push(v, PA, a, b);
	}
}

void	ft_try_rev_rotate(t_vars *v, t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 1 && ft_is_smallest(ft_lstlast(*a), *a) == __TRUE && \
	ft_lstsize(*b) > 1 && ft_is_biggest(ft_lstlast(*b), *b) == __TRUE)
	{
		if (ft_lstsize(*a) == 3 && ft_rev_sorted(*a) == __TRUE && \
		ft_lstsize(*b) == 3 && ft_is_sorted(*b) == __TRUE)
			return ;
		ft_rev_rotate(v, RRR, a, b);
	}
	else if (ft_lstsize(*a) > 1 && ft_is_smallest(ft_lstlast(*a), *a) == __TRUE)
	{
		if (ft_lstsize(*a) == 3 && ft_rev_sorted(*a) == __TRUE)
			return ;
		ft_rev_rotate(v, RRA, a, b);
	}
	else if (ft_lstsize(*b) > 1 && ft_is_biggest(ft_lstlast(*b), *b) == __TRUE)
	{
		if (ft_lstsize(*b) == 3 && ft_is_sorted(*b) == __TRUE)
			return ;
		ft_rev_rotate(v, RRB, a, b);
	}
}

void	ft_try_rotate(t_vars *v, t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 1 && \
	ft_is_biggest(*a, (*a)->next) == __TRUE && \
	ft_lstsize(*b) > 1 && \
	ft_is_smallest(*b, (*b)->next) == __TRUE)
		ft_rotate(v, RR, a, b);
	else if (ft_lstsize(*a) > 1 && \
	ft_is_biggest(*a, (*a)->next) == __TRUE)
		ft_rotate(v, RA, a, b);
	else if (ft_lstsize(*b) > 1 && ft_is_smallest(*b, (*b)->next) == __TRUE)
		ft_rotate(v, RB, a, b);
}

void	ft_alltry(t_vars *v)
{
	ft_try_swap(v, &v->a, &v->b);
	ft_try_push(v, &v->a, &v->b);
}
