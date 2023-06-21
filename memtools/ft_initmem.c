/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:56:06 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/14 14:14:16 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memtools.h"

t_vars	*ft_init_tvars(int argc)
{
	t_vars	*v;

	v = NULL;
	v = ft_calloc(1, sizeof(t_vars));
	if (!v)
		return (NULL);
	v->argc = argc;
	v->argv = NULL;
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

void	ft_join(t_vars *v, char **args, char *str)
{
	char	*las;

	las = *args;
	*args = ft_strjoin(*args, str);
	if (las)
		free(las);
	if (!*args)
		ft_prcss_exit(v, EXIT_FAILURE);
}

void	ft_init_argv(t_vars *v, int argc, char **argv)
{
	char	*args;
	int		i;

	i = 2;
	args = NULL;
	if (!ft_strlen(argv[1]))
		ft_prcss_exit(v, EXIT_SUCCESS);
	args = ft_strdup(argv[1]);
	if (!args)
		ft_prcss_exit(v, EXIT_FAILURE);
	while (i < argc)
	{
		if (!ft_strlen(argv[i]))
			ft_prcss_exit(v, EXIT_FAILURE);
		ft_join(v, &args, " ");
		ft_join(v, &args, argv[i]);
		i++;
	}
	v->argv = ft_split(args, ' ');
	free(args);
	if (!v->argv)
		ft_prcss_exit(v, EXIT_FAILURE);
	if (!v->argv[0])
		ft_prcss_exit(v, EXIT_SUCCESS);
}
