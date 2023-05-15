/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:09:33 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/14 00:12:27 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTRUCTIONS_H
# define FT_INSTRUCTIONS_H

# include "../ft_push_swap.h"

void	ft_push(t_vars *v, t_instr instruc, t_list **a, t_list **b);
void	ft_rev_rotate(t_vars *v, t_instr instruc, t_list **a, t_list **b);
void	ft_rotate(t_vars *v, t_instr instruc, t_list **a, t_list **b);
void	ft_swap(t_vars *v, t_instr instruc, t_list **a, t_list **b);

#endif