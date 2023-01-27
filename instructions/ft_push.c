/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:57:05 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/27 18:22:09 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*Prend le premier élément au sommet de la liste source et le met sur
la deuxiéme liste*/

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

void	ft_push(t_instr instruc, t_list **a, t_list **b)
{
	if (instruc == PA)
	{
		ft_op_push(b, a);
		ft_print_instruc(instruc);
	}
	else if (instruc == PB)
	{
		ft_op_push(a, b);
		ft_print_instruc(instruc);
	}
}

void	ft_try_push(t_list **a, t_list **b)
{
	if (*a && ft_cmp_content(*a, (*a)->next) == INFERIOR && \
	ft_is_sorted((*a)->next) == __FALSE)
	{
		ft_push(PB, a, b);
		return ;
	}
	if (ft_is_sorted(*a) == __TRUE)
	{
		if (ft_rev_sorted(*b) == __TRUE)
		{
			while (*b)
				ft_push(PA, a, b);
		}
		else if (*b)
			ft_push(PA, a, b);
	}
}
