/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:53:55 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/23 22:52:11 by TheTerror        ###   ########lyon.fr   */
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
	// ft_sort_small(v, __TRUE);
	// ft_sort_small(v, __FALSE);
	// ft_sort_bigone(v);
v->final = __TRUE;
	ft_sort_bigtwo(v);
	// ft_sort_typa(v);
	// ft_loader(v);
	ft_prcss_exit(v, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	ft_loader(t_vars *v)
{
	v->final = __TRUE;
	if (v->_1st > 0 && v->_1st <= v->_2nd && v->_1st <= v->_3rd && v->_1st <= v->_1st2)
	{

// ft_putendl_fd("1st", 1);
		ft_sort_small(v, __TRUE);
	}
	else if (v->_1st2 > 0 && v->_1st2 <= v->_2nd && v->_1st2 <= v->_3rd && v->_1st2 <= v->_1st)
	{
// ft_putendl_fd("1st2", 1);
		ft_sort_small(v, __FALSE);
	}
	else if (v->_2nd > 0 && v->_2nd <= v->_1st && v->_2nd <= v->_3rd && v->_2nd <= v->_1st2)
	{
// ft_putendl_fd("2nd", 1);
		ft_sort_bigone(v);
	}
	else if (v->_3rd > 0 && v->_3rd <= v->_2nd && v->_3rd <= v->_1st && v->_3rd <= v->_1st2)
	{
// ft_putendl_fd("3rd", 1);
		ft_sort_typa(v);
	}
	ft_prcss_exit(v, EXIT_SUCCESS);
}

void	ft_iter_args(t_vars *v, t_list **lst, int nargs, char **args)
{
	int		i;

	if (nargs < 2)
		ft_prcss_exit(v, EXIT_FAILURE);
	i = 1;
// ft_putendl_fd("", 1);
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
// ft_putstr_fd(args[i], 1);
// ft_putstr_fd(" ", 1);
		i++;
	}
// ft_putendl_fd("", 1);
	if (ft_is_sorted(v->a))
		ft_prcss_exit(v, EXIT_SUCCESS);
	v->len = ft_lstsize(v->a);
}

void	ft_prcss_exit(t_vars *v, int msg)
{
	if (msg == EXIT_FAILURE)
		ft_putendl_fd("Error", 2);
	ft_free_tvars(v);
	exit(msg);
}
