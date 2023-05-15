/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocss.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:13:59 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/15 16:08:25 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCSS_H
# define FT_PREPROCSS_H

# include "libft/libft.h"

# define __NTR 999//Nothing_To_Report
# define __INT_MIN -2147483648
# define __INT_MAX 2147483647
# define __NULL 0

typedef enum e_instr	t_instr;
typedef enum e_bool		t_bool;
typedef enum e_assert	t_assert;

enum e_instr
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

enum e_bool
{
	__FALSE = 0,
	__TRUE = 1
};

enum e_assert
{
	INFERIOR = -2,
	EQUAL = 1,
	SUPERIOR = 2
};

typedef struct s_vars
{
	int		argc;
	char	**argv;
	t_list	*a;
	t_list	*b;
	t_bool	final;
	int		count;
	int		fst;
	int		snd;
}				t_vars;


#endif
