/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enhance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:01:51 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/31 15:30:28 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_1st_sorter.h"

void	ft_try_rotate(t_vars *v, t_list **a, t_list **b);
void	ft_try_rev_rotate(t_vars *v, t_list **a, t_list **b);
void	ft_try_swap(t_vars *v, t_list **a, t_list **b);

void	ft_enhancexi(t_vars *v)
{
	if (ft_lstsize(v->a) <= 3 && ft_cmp_content(v->a, v->a->next) == INFERIOR \
		&& ft_cmp_content(v->a, ft_lstlast(v->a)) == INFERIOR \
		&& ft_is_biggest(v->a->next, v->a))
	{
		ft_swap(v, SA, &v->a, &v->b);
		ft_rotate(v, RA, &v->a, &v->b);
	}
}

void	ft_enhancexj(t_vars *v)
{
	ft_try_rev_rotate(v, &v->a, &v->b);
	ft_try_rotate(v, &v->a, &v->b);
	ft_try_swap(v, &v->a, &v->b);
}

void	ft_enhancexk(t_vars *v)
{
	if (ft_lstsize(v->a) > 3 && ft_is_biggest(v->a, v->a) && \
	*((int *) v->a->content) == *((int *) v->a->next->content) + 1)
	{
		ft_swap(v, SA, &v->a, &v->b);
		ft_rotate(v, RA, &v->a, &v->b);
		ft_rotate(v, RA, &v->a, &v->b);
	}
}

void	ft_enhancexl(t_vars *v)
{
	while (ft_cmp_content(ft_lstlast(v->a), v->a) == INFERIOR)
		ft_rev_rotate(v, RRA, &v->a, &v->b);
}
