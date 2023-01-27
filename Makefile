# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 19:26:46 by TheTerror         #+#    #+#              #
#    Updated: 2023/01/27 18:11:04 by TheTerror        ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
UTILS_PATH = utils/
INSTRUCTIONS_PATH = instructions/
LIBFT_PATH = libft/

INCLUDE = ft_push_swap.h ft_preprocss.h $(LIBFT_PATH)libft.h $(UTILS_PATH)ft_utils.h \
			$(INSTRUCTIONS_PATH)ft_instructions.h
CFLAGS = 	-Wall -Werror -Wextra
CC = 		cc
RM = 		rm -rf

SRC_UTILS = $(addprefix $(UTILS_PATH), ft_check_utils1.c ft_build_list.c \
			ft_check_utils2.c ft_print_instruc.c ft_freecontent.c)
SRC_INSTRUCTIONS = $(addprefix $(INSTRUCTIONS_PATH), ft_swap.c ft_push.c ft_rev_rotate.c ft_rotate.c)
SRC = 	ft_push_swap.c $(SRC_UTILS) $(SRC_INSTRUCTIONS)
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ) $(INCLUDE)
	make -C $(LIBFT_PATH)
	make bonus -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a .
	$(CC) $(CFLAGS) $(SRC) $(INCLUDE) libft.a -o $(NAME)

clean :
	make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ) $(OBJ_BONUS)
fclean : clean
	make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME) libft.a
re : fclean all
