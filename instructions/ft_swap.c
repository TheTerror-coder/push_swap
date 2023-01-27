/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:47:55 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/26 18:01:09 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*Intervertit les 2 premiers éléments au sommet de la liste*/

#include "ft_instructions.h"

void	ft_op_swap(t_list **list)
{
	t_list	*elm2;

	if (*list && (*list)->next)
	{
		elm2 = (*list)->next;
		(*list)->next = (*list)->next->next;
		elm2->next = *list;
		*list = elm2;
	}
}

void	ft_swap(instr instruc, t_list **a, t_list **b)
{
	if (instruc == SA)
	{
		ft_op_swap(a);
		ft_print_instruc(instruc);
	}
	else if (instruc == SB)
	{
		ft_op_swap(b);
		ft_print_instruc(instruc);
	}
	else if (instruc == SS)
	{
		ft_op_swap(a);
		ft_op_swap(b);
		ft_print_instruc(instruc);
	}
	else
		printf("Probléme!!\n");
}

void	ft_try_swap(t_list **a, t_list **b)
{
	ft_try_rev_rotate(a, b);
	ft_try_rotate(a, b);
	if (*a && ft_cmp_content(*a, (*a)->next) == SUPERIOR &&\
	*b && ft_cmp_content(*b, (*b)->next) == INFERIOR)
		ft_swap(SS, a, b);
	else if (*a && ft_cmp_content(*a, (*a)->next) == SUPERIOR)
		ft_swap(SA, a, b);
	else if (*b && ft_cmp_content(*b, (*b)->next) == INFERIOR)
		ft_swap(SB, a, b);
}
