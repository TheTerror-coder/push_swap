/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:56:06 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/23 15:42:15 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memtools.h"

t_vars	*ft_init_tvars(int argc, char **argv)
{
	t_vars	*v;

	v = NULL;
	v = ft_calloc(1, sizeof(t_vars));
	if (!v)
		return (NULL);
	v->argc = argc;
	v->argv =argv;
	v->a = NULL;	
	v->b = NULL;
	v->final = __FALSE;
	v->_1st = __INT_MAX;
	v->_1st2 = __INT_MAX;
	v->_2nd = __INT_MAX;
	v->_3rd = __INT_MAX;
	v->_4th = __INT_MAX;
	v->inst_st = RA;
	v->inst_nd = RA;
	v->inst = RA;
	return (v);
}