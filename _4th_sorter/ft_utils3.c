/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:13:26 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/31 15:35:12 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_4th_sorter.h"

void	ft_getibig(t_vars *v, int *i);
void	ft_getiinf(t_vars *v, int *i);
void	ft_drivebig_up(t_vars *v);
void	ft_driveinf_up(t_vars *v);

void	ft_readyb(t_vars *v)
{
	if (ft_is_smallest(v->a, v->b) || ft_is_biggest(v->a, v->b))
	{
		if (!ft_is_biggest(v->b, v->b))
			ft_drivebig_up(v);
		return ;
	}
	else
	{
		if (!(v->val > *((int *) v->b->content) && \
			v->val < *((int *) ft_lstlast(v->b)->content)))
			ft_driveinf_up(v);
		return ;
	}
}

void	ft_looprot(t_vars *v, int i, t_instr inst)
{
	int	x;

	x = 0;
	while (x < i)
	{
		if (inst == RB)
			ft_rotate(v, inst, &v->a, &v->b);
		else if (inst == RRB)
			ft_rev_rotate(v, inst, &v->a, &v->b);
		x++;
	}
}

void	ft_drivebig_up(t_vars *v)
{
	int		i;

	i = 0;
	ft_getibig(v, &i);
	if (i == ft_lstsize(v->b))
		ft_prcss_exit(v, EXIT_FAILURE);
	else if (i <= ft_lstsize(v->b) / 2)
		ft_looprot(v, i, RB);
	else
	{
		i = ft_lstsize(v->b) - i;
		ft_looprot(v, i, RRB);
	}
}

void	ft_driveinf_up(t_vars *v)
{
	int		i;

	i = 0;
	ft_getiinf(v, &i);
	if (i >= ft_lstsize(v->b))
		ft_prcss_exit(v, EXIT_FAILURE);
	else if (i <= ft_lstsize(v->b) / 2)
		ft_looprot(v, i, RB);
	else
	{
		i = ft_lstsize(v->b) - i;
		ft_looprot(v, i, RRB);
	}
}
