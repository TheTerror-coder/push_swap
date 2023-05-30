/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4th_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:44:56 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/29 20:06:11 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_4th_sorter.h"

t_bool	ft_sethold(t_vars *v);
void	ft_looppusha(t_vars *v);
void	ft_init4thtools(t_vars *v);
void	ft_readya(t_vars *v);
void	ft_readyb(t_vars *v);
void	ft_drivebig_up(t_vars *v);
void	ft_sort_bigtwo_op(t_vars *v);

void	ft_sort_bigtwo(t_vars *v)
{
	int	i;
	int	len;
	int	chunk;
	int	chstep;

	i = -2;
	len = __INT_MAX;
	if (v->len < 250)
		chstep = 5;
	else
		chstep = 11;
v->final = __FALSE;
	while (i < 3)
	{
		v->chunks = chstep + i;
		ft_sort_bigtwo_op(v);
		if (v->count < len)
		{
			chunk = v->chunks;
			len = v->count;
		}
		i++;
	}
v->final = __TRUE;
	v->chunks = chunk;
	// v->chunks = 5;
	ft_sort_bigtwo_op(v);
}

void	ft_sort_bigtwo_op(t_vars *v)
{
	v->count = 0;
	ft_rebuild(v);
	ft_mka_ulst(v);
	ft_init4thtools(v);
// t_list	*a;

// a = v->a;
// while (a)
// {
// 	printf("%d ", *((int *) a->content));
// 	a = a->next;
// }
// printf("\n");
	while (ft_lstsize(v->a))
	{
		if (ft_lstsize(v->a) > 1)
		{
// if (v->val == 4)
// {
// a = v->a;
// while (a)
// {
// 	printf("%d ", *((int *) a->content));
// 	a = a->next;
// }
// printf("\n");
// a = v->b;
// while (a)
// {
// 	printf("%d ", *((int *) a->content));
// 	a = a->next;
// }
// printf("\n");
// ft_prcss_exit(v, EXIT_FAILURE);
// }
			ft_sethold(v);
			ft_readya(v);
// printf("bigup\n");
		}
		else
			v->val = *((int *) v->a->content);
		if (ft_lstsize(v->b) > 1)
			ft_readyb(v);
		ft_push(v, PB, &v->a, &v->b);
	}
	if (!ft_is_biggest(v->b, v->b))
		ft_drivebig_up(v);
// a = v->b;
// while (a)
// {
// 	printf("%d ", *((int *) a->content));
// 	a = a->next;
// }
// printf("\n");
// ft_prcss_exit(v, EXIT_FAILURE);
	if (ft_rev_sorted(v->b))
		ft_looppusha(v);
	else
		ft_prcss_exit(v, EXIT_FAILURE);
	v->_4th = v->count;
// ft_putendl_fd("all good", 1);
}

void	ft_looppusha(t_vars *v)
{
	while (ft_lstsize(v->b))
		ft_push(v, PA, &v->a, &v->b);
}
void	ft_init4thtools(t_vars *v)
{
	v->vinf = 0;
	v->vsup = (v->len / v->chunks);
	v->holded = -1;
	v->hold_st = -1;
	v->hold_nd = -1;
	if (v->chunks > v->len)
		ft_prcss_exit(v, EXIT_FAILURE);
}