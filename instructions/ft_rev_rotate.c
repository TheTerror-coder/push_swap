/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:38:48 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/26 18:00:14 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*Décale d’une position vers le bas tous les élements de la liste.
Le dernier élément devient le premier.*/

#include "ft_instructions.h"

void	ft_op_rev_rotate(t_list **list)
{
	t_list	*last;
	t_list	*new_last;

	if (*list && (*list)->next)
	{
		last = ft_lstlast(*list);
		new_last = *list;
		while (new_last->next != last)
			new_last = new_last->next;
		if (new_last->next == last)
			new_last->next = NULL;
		ft_lstadd_front(list, last);
	}
}

void	ft_rev_rotate(instr instruc, t_list **a, t_list **b)
{
	if (instruc == RRA)
	{
		ft_op_rev_rotate(a);
		ft_print_instruc(instruc);
	}
	else if (instruc == RRB)
	{
		ft_op_rev_rotate(b);
		ft_print_instruc(instruc);
	}
	else if (instruc == RRR)
	{
		ft_op_rev_rotate(a);
		ft_op_rev_rotate(b);
		ft_print_instruc(instruc);
	}
	else
		printf("Probléme!!\n");
}

void	ft_try_rev_rotate(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 1 && ft_is_smallest(ft_lstlast(*a), *a) == __TRUE && \
	ft_lstsize(*b) > 1 && ft_is_biggest(ft_lstlast(*b), *b) == __TRUE)
	{
		if (ft_lstsize(*a) == 3 && ft_rev_sorted(*a) == __TRUE && \
		ft_lstsize(*b) == 3 && ft_is_sorted(*b) == __TRUE)
			return ;
		ft_rev_rotate(RRR, a, b);
	}
	else if (ft_lstsize(*a) > 1 && ft_is_smallest(ft_lstlast(*a), *a) == __TRUE)
	{
		if (ft_lstsize(*a) == 3 && ft_rev_sorted(*a) == __TRUE)
			return ;
		ft_rev_rotate(RRA, a, b);
	}
	else if (ft_lstsize(*b) > 1 && ft_is_biggest(ft_lstlast(*b), *b) == __TRUE)
	{
		if (ft_lstsize(*b) == 3 && ft_is_sorted(*b) == __TRUE)
			return ;
		ft_rev_rotate(RRB, a, b);
	}
}
