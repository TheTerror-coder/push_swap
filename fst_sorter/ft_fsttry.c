/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsttry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:48:16 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/13 21:50:50 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fst_sorter.h"

void	ft_try_swap(t_list **a, t_list **b)
{
	ft_try_rev_rotate(a, b);
	ft_try_rotate(a, b);
	if (*a && ft_cmp_content(*a, (*a)->next) == SUPERIOR && \
	*b && ft_cmp_content(*b, (*b)->next) == INFERIOR)
		ft_swap(SS, a, b);
	else if (*a && ft_cmp_content(*a, (*a)->next) == SUPERIOR)
		ft_swap(SA, a, b);
	else if (*b && ft_cmp_content(*b, (*b)->next) == INFERIOR)
		ft_swap(SB, a, b);
}

void	ft_try_push(t_list **a, t_list **b)
{
	if (*a && ft_cmp_content(*a, (*a)->next) == INFERIOR && \
	ft_is_sorted((*a)->next) == __FALSE)
	{
		ft_push(PB, a, b);
		return ;
	}
	if (ft_is_sorted(*a) == __TRUE)
	{
		if (ft_rev_sorted(*b) == __TRUE)
		{
			while (*b)
				ft_push(PA, a, b);
		}
		else if (*b)
			ft_push(PA, a, b);
	}
}

void	ft_try_rev_rotate(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 1 && ft_is_smallest(ft_lstlast(*a), *a) == __TRUE && \
	ft_lstsize(*b) > 1 && ft_is_biggest(ft_lstlast(*b), *b) == __TRUE)
	{
		if (ft_lstsize(*a) == 3 && ft_rev_sorted(*a) == __TRUE && \
		ft_lstsize(*b) == 3 && ft_is_sorted(*b) == __TRUE)
			return ;
		ft_rev_rotate(RRR, a, b);
	}
	else if (ft_lstsize(*a) > 1 && ft_is_smallest(ft_lstlast(*a), *a) == __TRUE)
	{
		if (ft_lstsize(*a) == 3 && ft_rev_sorted(*a) == __TRUE)
			return ;
		ft_rev_rotate(RRA, a, b);
	}
	else if (ft_lstsize(*b) > 1 && ft_is_biggest(ft_lstlast(*b), *b) == __TRUE)
	{
		if (ft_lstsize(*b) == 3 && ft_is_sorted(*b) == __TRUE)
			return ;
		ft_rev_rotate(RRB, a, b);
	}
}

void	ft_try_rotate(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 1 && \
	ft_is_biggest(*a, (*a)->next) == __TRUE && \
	ft_lstsize(*b) > 1 && \
	ft_is_smallest(*b, (*b)->next) == __TRUE)
		ft_rotate(RR, a, b);
	else if (ft_lstsize(*a) > 1 && \
	ft_is_biggest(*a, (*a)->next) == __TRUE)
		ft_rotate(RA, a, b);
	else if (ft_lstsize(*b) > 1 && ft_is_smallest(*b, (*b)->next) == __TRUE)
		ft_rotate(RB, a, b);
}
