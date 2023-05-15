/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:53:55 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/15 16:10:51 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_loader(t_vars *v);
void	ft_prcss_exit(t_vars *v, int msg);
void	ft_iter_args(t_vars *v, t_list **lst, int nargs, char **args);

int	main(int argc, char *argv[])
{
	t_vars	*v;

	v = ft_init_tvars(argc, argv);
	if (!v)
		ft_prcss_exit(v, EXIT_FAILURE);
	ft_iter_args(v, &v->a, argc, argv);
	ft_sort_small(v);
	ft_loader(v);
	ft_prcss_exit(v, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	ft_loader(t_vars *v)
{
	v->final = __TRUE;
	if (v->fst < v->snd)
		ft_sort_small(v);
	ft_prcss_exit(v, EXIT_SUCCESS);		
}

void	ft_iter_args(t_vars *v, t_list **lst, int nargs, char **args)
{
	int		i;

	if (nargs < 2)
		ft_prcss_exit(v, EXIT_FAILURE);
	i = 1;
	while (i < nargs)
	{
		if (ft_is_int(args[i]) == __FALSE)
			ft_prcss_exit(v, EXIT_FAILURE);
		if (ft_fit_in_int(args[i]) == __FALSE)
			ft_prcss_exit(v, EXIT_FAILURE);
		if (!ft_build_lst(lst, ft_build_content(args[i])))
			ft_prcss_exit(v, EXIT_FAILURE);
		if (ft_check_doubl(lst) == __FALSE)
			ft_prcss_exit(v, EXIT_FAILURE);
		i++;
	}
}

void	ft_prcss_exit(t_vars *v, int msg)
{
	ft_free_tvars(v);
	if (msg == EXIT_FAILURE)
		ft_putendl_fd("Error", 2);
	exit(msg);
}
