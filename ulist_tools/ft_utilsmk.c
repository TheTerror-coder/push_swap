/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsmk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:32:08 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/18 17:57:18 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ulist_tools.h"

int	ft_minevw(t_list *a, int min)
{
	while (a)
	{
		if (*((int *) a->content) != min)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_rset_ulstutils(t_vars *v)
{
	v->vmin = 0;
	v->vinf = 0;
	v->vsup = 0;
	v->val = 0;
	v->at_i = 0;
	v->inc = 0;
}

void	ft_setvmin_0(t_vars *v)
{
	int		i;
	t_list	*a;

	a = v->a;
	i = 0;
	while (a)
	{
		v->vsup = *((int *) a->content);
		if (i == 0)
		{
			v->val = *((int *) a->content);
			v->at_i = 0;
		}
		else if (v->vsup < v->val)
		{
			v->val = v->vsup;
			v->at_i = i;
		}
		i++;
		a = a->next;
	}
	v->vmin = v->val;
}


void	ft_setvmin_in(t_vars *v)
{
	int		i;
	t_list	*a;

	i = 0;
	a = v->a;
	while (i != v->at_i)
	{
		i++;
		a = a->next;
	}
	*((int *) a->content) = v->vmin;
}
