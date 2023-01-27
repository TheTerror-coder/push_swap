/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:41:23 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/27 17:30:16 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_bool	ft_check_doubl(t_list **lst)
{
	t_list	*elm1;
	t_list	*elm2;

	elm1 = *lst;
	elm2 = NULL;
	while (elm1)
	{
		elm2 = elm1->next;
		while (elm2)
		{
			if (ft_cmp_content(elm1, elm2) == EQUAL)
				return (__FALSE);
			elm2 = elm2->next;
		}
		elm1 = elm1->next;
	}
	return (__TRUE);
}

t_bool	ft_fit_in_int(char *arg)
{
	int			i;
	int			sign;
	long int	nbr;
	char		tab[2];

	i = 0;
	sign = 1;
	nbr = 0;
	tab[0] = '0';
	tab[1] = '\0';
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i] == '-')
			sign *= -1;
		i++;
	}
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		tab[0] = arg[i];
		nbr = (nbr * 10) + ft_atoi(tab);
		if (nbr * sign > __INT_MAX__ || nbr * sign < __INT_MIN)
			return (__FALSE);
		i++;
	}
	return (__TRUE);
}

t_bool	ft_is_int(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (ft_isalnum(arg[i]) != 1)
			return (__FALSE);
		i++;
	}
	return (__TRUE);
}
