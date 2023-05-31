/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_holdtools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:57:55 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/30 21:05:01 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_4th_sorter.h"

t_bool	ft_fitchunk(t_vars *v, t_list *elm);
t_bool	ft_setholdsecond(t_vars *v);
t_bool	ft_setholdfirst(t_vars *v);
void	ft_setter(t_vars *v);
void	ft_check_stpos(t_vars *v);
void	ft_check_ndpos(t_vars *v);

t_bool	ft_sethold(t_vars *v)
{
	v->inst_st = RA;
	v->inst_nd = RA;
	v->inst = RA;
	while (!ft_setholdfirst(v) && v->vinf <= v->len)
	{
		v->vinf += (v->len / v->chunks);
		v->vsup += (v->len / v->chunks);
	}
	if (v->vinf > v->len)
		return (__FALSE);
	ft_check_stpos(v);
	if (ft_setholdsecond(v))
	{
		ft_check_ndpos(v);
		ft_setter(v);
	}
	else
	{
		v->elm = v->elm_st;
		v->holded = v->hold_st;
		v->inst = v->inst_st;
		v->val = *((int *) v->elm_st->content);
	}
	return (__TRUE);
}

t_bool	ft_setholdfirst(t_vars *v)
{
	int		i;

	i = 0;
	v->elm_st = v->a;
	v->hold_st = -1;
	while (v->elm_st)
	{
		if (ft_fitchunk(v, v->elm_st))
		{
			v->hold_st = i;
			return (__TRUE);
		}
		i++;
		v->elm_st = v->elm_st->next;
	}
	return (__FALSE);
}

t_bool	ft_setholdsecond(t_vars *v)
{
	int		i;
	t_list	*a;

	i = 0;
	a = v->a;
	v->hold_nd = -1;
	while (a)
	{
		if (ft_fitchunk(v, a))
		{
			v->elm_nd = a;
			v->hold_nd = i;
		}
		i++;
		a = a->next;
	}
	if (v->hold_nd >= 0 && v->hold_nd != v->hold_st)
		return (__TRUE);
	return (__FALSE);
}
