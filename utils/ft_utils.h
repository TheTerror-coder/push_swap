/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:01:35 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/27 18:19:12 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "../ft_push_swap.h"

int			*ft_build_content(char *arg);
void		*ft_build_lst(t_list **lst, int *content);
t_bool		ft_check_doubl(t_list **lst);
t_bool		ft_fit_in_int(char *arg);
t_bool		ft_is_int(char *arg);
void		ft_freecontent(void *content);
void		ft_print_instruc(t_instr instruc);
t_assert	ft_cmp_content(t_list *elm1, t_list *elm2);
t_bool		ft_is_sorted(t_list *lst);
t_bool		ft_rev_sorted(t_list *lst);
t_bool		ft_is_smallest(t_list *elm, t_list *lst);
t_bool		ft_is_biggest(t_list *elm, t_list *lst);

#endif