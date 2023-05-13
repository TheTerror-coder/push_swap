/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:12:57 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/13 22:46:45 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memtools.h"

void	ft_free_tvars(t_vars *v)
{
	if (v->a)
		ft_lstclear(&v->a, &ft_freecontent);
	if (v->b)
		ft_lstclear(&v->b, &ft_freecontent);
}
