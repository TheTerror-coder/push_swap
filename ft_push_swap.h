/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:49:43 by TheTerror         #+#    #+#             */
/*   Updated: 2023/01/25 19:32:54 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
#include "libft/libft.h"
#include<stdlib.h>
#include<stdio.h>

# define __NTR ((void *) 999)//Nothing_To_Report
# define __INT_MIN -2147483648
# define __NULL 0

typedef enum instr instr;
typedef enum boole boole;
typedef enum assert assert;

enum instr{
	SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
};

enum boole{
	__FALSE = -1, __TRUE = 1
};

enum assert{
	INFERIOR = -2, EQUAL = 1, SUPERIOR = 2
};

#include "instructions/ft_instructions.h"
#include "utils/ft_utils.h"

#endif