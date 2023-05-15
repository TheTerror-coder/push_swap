/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:56:28 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/14 13:33:51 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMTOOLS_H
# define FT_MEMTOOLS_H

# include "../ft_push_swap.h"

t_vars	*ft_init_tvars(int argc, char **argv);
void	ft_free_tvars(t_vars *v);

#endif
