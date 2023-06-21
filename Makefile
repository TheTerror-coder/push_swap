# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 19:26:46 by TheTerror         #+#    #+#              #
#    Updated: 2023/06/13 15:38:53 by TheTerror        ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_A = $(LIBFT_PATH)libft.a

UTILS_PATH = ./utils/
MEMTOOLS_PATH = ./memtools/
_1ST_SORTER_PATH = ./_1st_sorter/
_2ND_SORTER_PATH = ./_2nd_sorter/
_3RD_SORTER_PATH = ./_3rd_sorter/
_4TH_SORTER_PATH = ./_4th_sorter/
ULIST_TOOLS_PATH = ./ulist_tools/
INSTRUCTIONS_PATH = ./instructions/
LIBFT_PATH = ./libft/


INCLUDE = 	ft_push_swap.h ft_preprocss.h $(LIBFT_PATH)libft.h $(UTILS_PATH)ft_utils.h \
			$(INSTRUCTIONS_PATH)ft_instructions.h $(MEMTOOLS_PATH)ft_memtools.h \
			$(_1ST_SORTER_PATH)ft_1st_sorter.h $(_2ND_SORTER_PATH)ft_2nd_sorter.h \
			$(ULIST_TOOLS_PATH)ft_ulist_tools.h $(_3RD_SORTER_PATH)ft_3rd_sorter.h \
			$(_4TH_SORTER_PATH)ft_4th_sorter.h


CFLAGS = 	-Wall -Werror -Wextra
CC = 		cc
RM = 		rm -rf

SRC_1ST_SORTER = $(addprefix $(_1ST_SORTER_PATH), ft_1st_algo.c ft_1st_try.c ft_enhance.c)
SRC_2ND_SORTER = $(addprefix $(_2ND_SORTER_PATH), ft_2nd_algo.c ft_2nd_utils.c)
SRC_3RD_SORTER = $(addprefix $(_3RD_SORTER_PATH), ft_3rd_algo.c)
SRC_4TH_SORTER = $(addprefix $(_4TH_SORTER_PATH), ft_4th_algo.c ft_holdtools.c ft_utils1.c \
			ft_utils2.c ft_utils3.c ft_utils4.c)
SRC_ULIST_TOOLS = $(addprefix $(ULIST_TOOLS_PATH), ft_mkulist.c ft_utilsmk.c)
SRC_MEMTOOLS = $(addprefix $(MEMTOOLS_PATH), ft_initmem.c ft_freemem.c)
SRC_UTILS = $(addprefix $(UTILS_PATH), ft_check_utils1.c ft_build_list.c \
			ft_check_utils2.c ft_print_instruc.c ft_freecontent.c)
SRC_INSTRUCTIONS = $(addprefix $(INSTRUCTIONS_PATH), ft_swap.c ft_push.c ft_rev_rotate.c ft_rotate.c)
SRC = 	ft_push_swap.c $(SRC_UTILS) $(SRC_INSTRUCTIONS) $(SRC_MEMTOOLS) $(SRC_1ST_SORTER) \
		$(SRC_2ND_SORTER) $(SRC_ULIST_TOOLS) $(SRC_3RD_SORTER) $(SRC_4TH_SORTER)



OBJ = $(SRC:.c=.o)

all : make_libft $(NAME)

%.o : %.c $(INCLUDE) $(LIBFT_A)
	$(CC) $(CFLAGS) -c -o $@ $<

make_libft :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(INCLUDE) -o $(NAME)

clean :
	make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ) $(OBJ_BONUS)
fclean : clean
	make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME) libft.a
re : fclean all
