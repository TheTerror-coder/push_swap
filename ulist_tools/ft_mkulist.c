/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkulist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:30:46 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/31 15:38:40 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ulist_tools.h"

int		ft_minevw(t_list *a, int min);
void	ft_loopulst(t_vars *v);
void	ft_setvmin_0(t_vars *v);
void	ft_set_val(t_vars *v, int val, int index);
void	ft_setvmin_in(t_vars *v);
void	ft_reseta(t_vars *v);
void	ft_rset_ulstutils(t_vars *v);

void	ft_mka_ulst(t_vars *v)
{
	ft_rset_ulstutils(v);
	v->ulst = ft_calloc(ft_lstsize(v->a), sizeof(int));
	if (!v->ulst)
		ft_prcss_exit(v, EXIT_FAILURE);
	ft_setvmin_0(v);
	v->ulst[v->at_i] = v->inc;
	v->vinf = v->vmin;
	while (!ft_minevw(v->a, v->vmin))
	{
		ft_loopulst(v);
		v->inc++;
		v->ulst[v->at_i] = v->inc;
		v->vinf = v->val;
		ft_setvmin_in(v);
	}
	ft_reseta(v);
	free(v->ulst);
	v->ulst = NULL;
}

void	ft_loopulst(t_vars *v)
{
	t_list	*a;
	int		i;

	i = 0;
	a = v->a;
	while (a)
	{
		v->vsup = *((int *) a->content);
		if (i == 0)
			ft_set_val(v, *((int *) a->content), 0);
		if (v->vsup > v->vinf && v->vsup < v->val)
			ft_set_val(v, v->vsup, i);
		else if (v->val <= v->vinf)
			ft_set_val(v, v->vsup, i);
		i++;
		a = a->next;
	}
}

void	ft_set_val(t_vars *v, int val, int index)
{
	v->val = val;
	v->at_i = index;
}

void	ft_reseta(t_vars *v)
{
	t_list	*a;
	int		i;

	i = 0;
	a = v->a;
	while (a)
	{
		*((int *) a->content) = v->ulst[i];
		i++;
		a = a->next;
	}
}
