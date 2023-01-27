/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:53:55 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/27 18:14:54 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_prcss_exit(t_list **a, t_list **b, int msg)
{
	if (a)
		ft_lstclear(a, &ft_freecontent);
	if (b)
		ft_lstclear(b, &ft_freecontent);
	if (msg == EXIT_FAILURE)
		ft_putendl_fd("Error", 2);
	exit(msg);
}

void	ft_iter_args(t_list **lst, int nargs, char **args)
{
	int		i;

	if (nargs < 2)
		ft_prcss_exit(lst, (t_list **) NULL, EXIT_FAILURE);
	i = 1;
	while (i < nargs)
	{
		if (ft_is_int(args[i]) == __FALSE)
			ft_prcss_exit(lst, (t_list **) NULL, EXIT_FAILURE);
		if (ft_fit_in_int(args[i]) == __FALSE)
			ft_prcss_exit(lst, (t_list **) NULL, EXIT_FAILURE);
		if (!ft_build_lst(lst, ft_build_content(args[i])))
			ft_prcss_exit(lst, (t_list **) NULL, EXIT_FAILURE);
		if (ft_check_doubl(lst) == __FALSE)
			ft_prcss_exit(lst, (t_list **) NULL, EXIT_FAILURE);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	ft_iter_args(&a, argc, argv);
	while (ft_is_sorted(a) == __FALSE || ft_lstsize(b))
	{
		ft_try_swap(&a, &b);
		ft_try_push(&a, &b);
	}
	ft_lstclear(&a, &ft_freecontent);
	ft_lstclear(&b, &ft_freecontent);
	return (EXIT_SUCCESS);
}
