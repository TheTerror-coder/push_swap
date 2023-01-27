/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:47:21 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/27 18:17:51 by TheTerror        ###   ########lyon.fr   */
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

void	*ft_build_lst(t_list **lst, int *content)
{
	t_list	*new;

	if (!content)
		return (NULL);
	new = ft_lstnew(content);
	if (!new)
	{
		ft_freecontent(content);
		return (NULL);
	}
	ft_lstadd_back(lst, new);
	return (__NTR);
}
