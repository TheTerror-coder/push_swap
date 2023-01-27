/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:54:30 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/27 18:22:25 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*Décale d’une position vers le haut tous les élements de la liste.
Le premier élément devient le dernier.*/

#include "ft_instructions.h"

void	ft_op_rotate(t_list **list)
{
	t_list	*elm;

	if (*list && (*list)->next)
	{
		elm = *list;
		*list = (*list)->next;
		elm->next = NULL;
		ft_lstadd_back(list, elm);
	}
}

void	ft_rotate(t_instr instruc, t_list **a, t_list **b)
{
	if (instruc == RA)
	{
		ft_op_rotate(a);
		ft_print_instruc(instruc);
	}
	else if (instruc == RB)
	{
		ft_op_rotate(b);
		ft_print_instruc(instruc);
	}
	else if (instruc == RR)
	{
		ft_op_rotate(a);
		ft_op_rotate(b);
		ft_print_instruc(instruc);
	}
}

void	ft_try_rotate(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 1 && \
	ft_is_biggest(*a, (*a)->next) == __TRUE && \
	ft_lstsize(*b) > 1 && \
	ft_is_smallest(*b, (*b)->next) == __TRUE)
		ft_rotate(RR, a, b);
	else if (ft_lstsize(*a) > 1 && \
	ft_is_biggest(*a, (*a)->next) == __TRUE)
		ft_rotate(RA, a, b);
	else if (ft_lstsize(*b) > 1 && ft_is_smallest(*b, (*b)->next) == __TRUE)
		ft_rotate(RB, a, b);
}
