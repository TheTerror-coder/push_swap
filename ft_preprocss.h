/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocss.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:13:59 by TheTerror         #+#    #+#             */
/*   Updated: 2023/05/31 15:40:35 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCSS_H
# define FT_PREPROCSS_H

# include "libft/libft.h"

# define __NTR 999//Nothing_To_Report
# define __NULL 0

typedef enum e_instr	t_instr;

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

typedef struct s_vars
{
	int		argc;
	char	**argv;
	t_list	*a;
	t_list	*b;
	t_bool	final;
	t_bool	flg;
	int		count;
	int		_1st;
	int		_1st2;
	int		_2nd;
	int		_3rd;
	int		_4th;
	int		nth;
	int		max_bit;
	int		len;
	int		*ulst;
	int		vmin;
	int		vinf;
	int		vsup;
	int		val;
	int		at_i;
	int		inc;
	int		chunks;
	int		hold_st;
	int		hold_nd;
	t_list	*elm_st;
	t_list	*elm_nd;
	t_list	*elm;
	int		holded;
	t_instr	inst_st;
	t_instr	inst_nd;
	t_instr	inst;
}				t_vars;

#endif
