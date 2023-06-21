/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instruc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:33:13 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/06 16:52:22 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_print_instruc(t_instr instruc)
{
	if (instruc == SA)
		ft_putendl_fd("sa", 1);
	if (instruc == SB)
		ft_putendl_fd("sb", 1);
	if (instruc == SS)
		ft_putendl_fd("ss", 1);
	if (instruc == PA)
		ft_putendl_fd("pa", 1);
	if (instruc == PB)
		ft_putendl_fd("pb", 1);
	if (instruc == RA)
		ft_putendl_fd("ra", 1);
	if (instruc == RB)
		ft_putendl_fd("rb", 1);
	if (instruc == RR)
		ft_putendl_fd("rr", 1);
	if (instruc == RRA)
		ft_putendl_fd("rra", 1);
	if (instruc == RRB)
		ft_putendl_fd("rrb", 1);
	if (instruc == RRR)
		ft_putendl_fd("rrr", 1);
}
