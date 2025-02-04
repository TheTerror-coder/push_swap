/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:57:05 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/06 16:51:21 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instructions.h"

void	ft_op_push(t_list **src, t_list **dst)
{
	t_list	*elm;

	if (*src)
	{
		elm = *src;
		*src = (*src)->next;
		ft_lstadd_front(dst, elm);
	}
}

void	ft_push(t_vars *v, t_instr instruc, t_list **a, t_list **b)
{
	if (instruc == PA)
	{
		ft_op_push(b, a);
		if (v->final)
			ft_print_instruc(instruc);
		else
			v->count++;
	}
	else if (instruc == PB)
	{
		ft_op_push(a, b);
		if (v->final)
			ft_print_instruc(instruc);
		else
			v->count++;
	}
}
