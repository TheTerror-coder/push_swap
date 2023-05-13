/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:56:06 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/13 22:46:45 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memtools.h"

t_vars	*ft_init_tvars()
{
	t_vars	*v;

	v = NULL;
	v = ft_calloc(1, sizeof(t_vars));
	if (!v)
		return (NULL);
	v->a = NULL;	
	v->b = NULL;
	return (v);
}