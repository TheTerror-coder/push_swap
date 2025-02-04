/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:38:48 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/06 16:51:10 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_rev_rotate(t_vars *v, t_instr instruc, t_list **a, t_list **b)
{
	if (instruc == RRA)
	{
		ft_op_rev_rotate(a);
		if (v->final)
			ft_print_instruc(instruc);
		else
			v->count++;
	}
	else if (instruc == RRB)
	{
		ft_op_rev_rotate(b);
		if (v->final)
			ft_print_instruc(instruc);
		else
			v->count++;
	}
	else if (instruc == RRR)
	{
		ft_op_rev_rotate(a);
		ft_op_rev_rotate(b);
		if (v->final)
			ft_print_instruc(instruc);
		else
			v->count++;
	}
}
