/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:12:49 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/26 14:25:27 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_4th_sorter.h"

void	ft_setter(t_vars *v)
{
	if (v->hold_st <= v->hold_nd)
	{
		v->elm = v->elm_st;
		v->holded = v->hold_st;
		v->inst = v->inst_st;
		v->val = *((int *) v->elm_st->content);
	}
	else
	{
		v->elm = v->elm_nd;
		v->holded = v->hold_nd;
		v->inst = v->inst_nd;
		v->val = *((int *) v->elm_nd->content);
	}
}

void	ft_check_stpos(t_vars *v)
{
	int	len;

	len = ft_lstsize(v->a);
	if (v->hold_st > (len / 2))
	{
		v->hold_st = len - v->hold_st;
		v->inst_st = RRA;
	}
}

void	ft_check_ndpos(t_vars *v)
{
	int	len;

	len = ft_lstsize(v->a);
	if (v->hold_nd > (len / 2))
	{
		v->hold_nd = len - v->hold_nd;
		v->inst_nd = RRA;
	}
}

t_bool	ft_fitchunk(t_vars *v, t_list *elm)
{
	if (*((int *) elm->content) >= v->vinf && *((int *) elm->content) < v->vsup)
		return (__TRUE);
	return (__FALSE);
}
