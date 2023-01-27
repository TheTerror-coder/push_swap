/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:01:35 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/25 18:39:23 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

#include "../ft_push_swap.h"

int		*ft_build_content(char *arg);
void	*ft_build_lst(t_list **lst, int *content);
boole	ft_check_doubl(t_list **lst);
boole	ft_fit_in_int(char *arg);
boole	ft_is_int(char *arg);
void	ft_freecontent(void *content);
void	ft_print_instruc(instr instruc);
assert	ft_cmp_content(t_list *elm1, t_list *elm2);
boole	ft_is_sorted(t_list *lst);
boole	ft_rev_sorted(t_list *lst);
boole	ft_is_smallest(t_list *elm, t_list *lst);
boole	ft_is_biggest(t_list *elm, t_list *lst);

#endif