/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:56:06 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/15 16:08:47 by TheTerror        ###   ########lyon.fr   */
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
	v->fst = __INT_MAX;
	v->snd = __INT_MAX;
	return (v);
}