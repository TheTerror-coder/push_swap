/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fst_sorter.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:35:53 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/15 15:27:26 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../ft_push_swap.h"

void	ft_sort_small(t_vars *v);
void	ft_try_rev_rotate(t_vars *v, t_list **a, t_list **b);
void	ft_try_rotate(t_vars *v, t_list **a, t_list **b);
void	ft_try_swap(t_vars *v, t_list **a, t_list **b);
void	ft_try_push(t_vars *v, t_list **a, t_list **b);