/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:47:21 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/31 13:00:21 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	*ft_build_content(char *arg)
{
	int	*content;

	content = NULL;
	content = malloc(sizeof(int));
	if (!content)
		return (NULL);
	*content = ft_atoi(arg);
	return (content);
}

int	ft_build_lst(t_list **lst, int *content)
{
	t_list	*new;

	if (!content)
		return (0);
	new = ft_lstnew(content);
	if (!new)
	{
		ft_freecontent(content);
		return (0);
	}
	ft_lstadd_back(lst, new);
	return (__NTR);
}

void	ft_rebuild(t_vars *v)
{
	int	i;

	i = 0;
	ft_lstclear(&v->a, &ft_freecontent);
	while (v->argv[i])
	{
		if (!ft_build_lst(&v->a, ft_build_content(v->argv[i])))
			ft_prcss_exit(v, EXIT_FAILURE);
		i++;
	}
}
