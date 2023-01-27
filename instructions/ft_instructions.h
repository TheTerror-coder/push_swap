/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:09:33 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/25 19:05:00 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTRUCTIONS_H
# define FT_INSTRUCTIONS_H

#include "../ft_push_swap.h"

void	ft_try_rev_rotate(t_list **a, t_list **b);
void	ft_try_rotate(t_list **a, t_list **b);
void	ft_try_swap(t_list **a, t_list **b);
void	ft_try_push(t_list **a, t_list **b);

#endif