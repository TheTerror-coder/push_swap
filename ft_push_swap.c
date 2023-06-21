/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:53:55 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/06 18:29:41 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_loader(t_vars *v);
void	ft_prcss_exit(t_vars *v, int msg);
void	ft_iter_args(t_vars *v, t_list **lst, int argc, char **argv);
void	ft_init_argv(t_vars *v, int argc, char **argv);

int	main(int argc, char *argv[])
{
	t_vars	*v;

	v = ft_init_tvars(argc);
	if (!v)
		ft_prcss_exit(v, EXIT_FAILURE);
	ft_iter_args(v, &v->a, argc, argv);
	if (v->len < 80)
		ft_sort_small(v, __TRUE);
	if (v->len < 80)
		ft_sort_small(v, __FALSE);
	if (v->len > 10 && v->len < 80)
		ft_sort_bigone(v);
	if (v->len > 10 && v->len < 80)
		ft_sort_typa(v);
	if (v->len >= 80)
		ft_sort_bigtwo(v);
	ft_loader(v);
	ft_prcss_exit(v, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	ft_loader(t_vars *v)
{
	v->final = __TRUE;
	if (v->_1st > 0 && \
		v->_1st <= v->_2nd && v->_1st <= v->_3rd && \
		v->_1st <= v->_1st2 && v->_1st <= v->_4th)
		ft_sort_small(v, __TRUE);
	else if (v->_1st2 > 0 && \
		v->_1st2 <= v->_2nd && v->_1st2 <= v->_3rd && \
		v->_1st2 <= v->_1st && v->_1st2 <= v->_4th)
		ft_sort_small(v, __FALSE);
	else if (v->_2nd > 0 && \
		v->_2nd <= v->_1st && v->_2nd <= v->_3rd && \
		v->_2nd <= v->_1st2 && v->_2nd <= v->_4th)
		ft_sort_bigone(v);
	else if (v->_3rd > 0 && \
		v->_3rd <= v->_2nd && v->_3rd <= v->_1st && \
		v->_3rd <= v->_1st2 && v->_3rd <= v->_4th)
		ft_sort_typa(v);
	else
		ft_sort_bigtwo(v);
	ft_prcss_exit(v, EXIT_SUCCESS);
}

void	ft_iter_args(t_vars *v, t_list **lst, int argc, char **argv)
{
	int		i;

	if (argc < 2)
		ft_prcss_exit(v, EXIT_SUCCESS);
	ft_init_argv(v, argc, argv);
	i = 0;
	while (v->argv[i])
	{
		if (ft_is_int(v->argv[i]) == __FALSE)
			ft_prcss_exit(v, EXIT_FAILURE);
		if (ft_fit_in_int(v->argv[i]) == __FALSE)
			ft_prcss_exit(v, EXIT_FAILURE);
		if (!ft_build_lst(lst, ft_build_content(v->argv[i])))
			ft_prcss_exit(v, EXIT_FAILURE);
		if (ft_check_doubl(lst) == __FALSE)
			ft_prcss_exit(v, EXIT_FAILURE);
		i++;
	}
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
