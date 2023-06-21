/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:54:30 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/06 16:51:34 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_rotate(t_vars *v, t_instr instruc, t_list **a, t_list **b)
{
	if (instruc == RA)
	{
		ft_op_rotate(a);
		if (v->final)
			ft_print_instruc(instruc);
		else
			v->count++;
	}
	else if (instruc == RB)
	{
		ft_op_rotate(b);
		if (v->final)
			ft_print_instruc(instruc);
		else
			v->count++;
	}
	else if (instruc == RR)
	{
		ft_op_rotate(a);
		ft_op_rotate(b);
		if (v->final)
			ft_print_instruc(instruc);
		else
			v->count++;
	}
}
