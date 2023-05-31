/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:39:24 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/30 21:21:05 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_4th_sorter.h"

void	ft_getibig(t_vars *v, int *i);
void	ft_getiinf(t_vars *v, int *i);
void	ft_swtch1(t_vars *v, t_list *elm);
void	ft_swtch2(t_vars *v, t_list *elm);

void	ft_readya(t_vars *v)
{
	int		i;
	t_instr	inst;

	i = 0;
	inst = v->inst;
	while (i < v->holded)
	{
		v->inst = inst;
		if (v->inst == RA)
		{
			ft_swtch1(v, v->elm);
			ft_rotate(v, v->inst, &v->a, &v->b);
		}
		else if (v->inst == RRA)
		{
			ft_swtch2(v, v->elm);
			ft_rev_rotate(v, v->inst, &v->a, &v->b);
		}
		i++;
	}
}

void	ft_swtch1(t_vars *v, t_list *elm)
{
	int	i;

	i = 0;
	if (ft_lstsize(v->b) > 1 && (ft_is_smallest(elm, v->b) || ft_is_biggest(elm, v->b)))
	{
		if (!ft_is_biggest(v->b, v->b))
		{
			ft_getibig(v, &i);
			if (i <= ft_lstsize(v->b) / 2)
				v->inst = RR;
		}
		return ;
	}
	else if (ft_lstsize(v->b) > 1 &&  !(v->val > *((int *) v->b->content) && \
			v->val < *((int *) ft_lstlast(v->b)->content)))
	{
		ft_getiinf(v, &i);
		if (i <= ft_lstsize(v->b) / 2)
			v->inst = RR;
	}
}

void	ft_swtch2(t_vars *v, t_list *elm)
{
	int	i;

	i = 0;
	if (ft_lstsize(v->b) > 1 && (ft_is_smallest(elm, v->b) || ft_is_biggest(elm, v->b)))
	{
		if (!ft_is_biggest(v->b, v->b))
		{
			ft_getibig(v, &i);
			if (i > ft_lstsize(v->b) / 2)
				v->inst = RRR;
		}
		return ;
	}
	else if (ft_lstsize(v->b) > 1 && !(v->val > *((int *) v->b->content) && \
			v->val < *((int *) ft_lstlast(v->b)->content)))
	{
		ft_getiinf(v, &i);
		if (i > ft_lstsize(v->b) / 2)
			v->inst = RRR;
	}
}

void	ft_getibig(t_vars *v, int *i)
{
	t_list	*b;

	*i = 0;
	b = v->b;
	while (b && !ft_is_biggest(b, v->b))
	{
		*i = *i + 1;
		b = b->next;
	}
}

void	ft_getiinf(t_vars *v, int *i)
{
	t_list	*b;

	*i = 0;
	b = v->b;
	if (!b)
		ft_prcss_exit(v, EXIT_FAILURE);
	while (b && !(v->val < *((int *) b->content) && \
			v->val > *((int *) b->next->content)))
	{
		*i = *i + 1;
		b = b->next;
	}
	*i = *i + 1;
}
