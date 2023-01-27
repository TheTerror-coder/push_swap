/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:53:55 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/27 16:52:54 by TheTerror        ###   ########lyon.fr   */
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

void	ft_printlist(t_list *list)
{
	while (list)
	{
		ft_putnbr_fd(*((int*) (list->content)), 1);
		ft_putchar_fd('\n', 1);
		list = list->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	// int n = 0;
	ft_iter_args(&a, argc, argv);

	// ft_printlist(a);
	// ft_putendl_fd("-\na\n", 1);
	// ft_printlist(b);
	// ft_putendl_fd("-\nb\n", 1);
	
	while (ft_is_sorted(a) == __FALSE || ft_lstsize(b))
	{
		ft_try_swap(&a, &b);
		ft_try_push(&a, &b);
	// ft_printlist(a);
	// ft_putendl_fd("-\na\n", 1);
	// ft_printlist(b);
	// ft_putendl_fd("-\nb\n", 1);
	// n++;
	// if (n > 7)
	// 	ft_prcss_exit(&a, &b, EXIT_FAILURE);
	}
	

	ft_lstclear(&a, &ft_freecontent);
	ft_lstclear(&b, &ft_freecontent);
	return (EXIT_SUCCESS);
}




// int	*ft_lloc(int n)
// {
// 	int	*ptr;

// 	ptr = NULL;
// 	ptr = malloc(sizeof(int));
// 	if (!ptr)
// 		return (NULL);
// 	*ptr = n;
// 	return (ptr);
// }
/*
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	ft_iter_args(&a, argc, argv);
	// ft_lstadd_front(&a, ft_lstnew(ft_lloc(5)));
	// ft_lstadd_front(&a, ft_lstnew(ft_lloc(8)));
	// ft_lstadd_front(&a, ft_lstnew(ft_lloc(1)));
	// ft_lstadd_front(&a, ft_lstnew(ft_lloc(9)));

	ft_printlist(a);
	ft_putendl_fd("-\na\n", 1);
	ft_printlist(b);
	ft_putendl_fd("-\nb\n", 1);
	
	ft_rotate(RA, &a, &b);
	ft_swap(SA, &a, &b);
	ft_push(PA, &a, &b);
	ft_rev_rotate(RRA, &a, &b);
	ft_push(PA, &a, &b);
	ft_swap(SB, &a, &b);
	ft_push(PB, &a, &b);
	ft_push(PB, &a, &b);
	ft_rotate(RA, &a, &b);
	ft_rotate(RA, &a, &b);
	// ft_printlist(a);
	// ft_putendl_fd("-\na\n", 1);
	// ft_printlist(b);
	// ft_putendl_fd("-\nb\n", 1);

	
	// ft_rev_rotate(RRR, &a, &b);
	// ft_printlist(a);
	// ft_putendl_fd("-\na\n", 1);
	// ft_printlist(b);
	// ft_putendl_fd("-\nb\n", 1);


	ft_lstclear(&a, &ft_freecontent);
	ft_lstclear(&b, &ft_freecontent);
	return (EXIT_SUCCESS);
}
*/