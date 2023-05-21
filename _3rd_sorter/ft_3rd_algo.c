/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3rd_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:55:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/21 13:11:23 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3rd_sorter.h"

void	ft_lnchpa(t_vars *v);
int		ft_asmallest(t_vars *v, t_list *a);
void	ft_lnchrot(t_vars *v, t_instr instr);

void	ft_sort_typa(t_vars *v)
{
	int	imin;

	imin = 0;
	v->count = 0;
	ft_rebuild(v);
	while (!ft_is_sorted(v->a))
	{
		imin = ft_asmallest(v, v->a);
		if (imin <= ft_lstsize(v->a) / 2)
			ft_lnchrot(v, RA);
		else
			ft_lnchrot(v, RRA);
		if (!ft_is_sorted(v->a))
			ft_push(v, PB, &v->a, &v->b);
	}
	while (ft_lstsize(v->b))
		ft_lnchpa(v);
	v->_3rd = v->count;
}
void	ft_lnchrot(t_vars *v, t_instr instr)
{
	while ((*((int *) v->a->content)) != v->vmin)
	{
		if (instr == RA)
			ft_rotate(v, instr, &v->a, &v->b);
		else if (instr == RRA)
			ft_rev_rotate(v, instr, &v->a, &v->b);
	}
}

int	ft_asmallest(t_vars *v, t_list *a)
{
	int		i;

	v->vmin = 0;
	i = 0;
	while (a)
	{
		if (ft_is_smallest(a, a))
		{
			v->vmin = *((int *) a->content);
			return (i);
		}
		i++;
		a = a->next;
	}
	ft_prcss_exit(v, EXIT_FAILURE);
	return (0);
}

void	ft_lnchpa(t_vars *v)
{
	while (ft_lstsize(v->b))
		ft_push(v, PA, &v->a, &v->b);
}