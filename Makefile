# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 13:28:09 by albben-a          #+#    #+#              #
#    Updated: 2026/03/11 11:35:51 by albben-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
NAME_BONUS 	= checker

HEADER 	 = push_swap.h
HEADER_BONUS = checker_bonus.h

CC      = cc
FLAGS   = -Wall -Wextra -Werror

SRC     =	main.c alg_adaptive.c alg_medium.c alg_simple.c\
			alg_complex_utils.c alg_complex_lis.c alg_complex.c benchmark_utils.c \
			choose_alg.c free_memory.c ft_split.c list_functions.c mov_push.c \
			mov_reverse_rotate.c mov_rotate.c mov_swap.c parser_args.c pos_utils.c \
			process_num.c stack_creator.c utils.c 

BSRC 	= 	main_bonus.c check_mov_bonus.c free_memory_bonus.c ft_split_bonus.c \
			get_next_line_bonus.c get_next_line_utils_bonus.c list_functions_bonus.c \
			mov_push_bonus.c mov_reverse_rotate_bonus.c mov_rotate_bonus.c mov_swap_bonus.c \
			process_num_bonus.c

OBJ     = $(SRC:.c=.o)
BOBJ 	= $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo " $(NAME) compiled and ready."

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BOBJ)
	@$(CC) $(FLAGS) $(BOBJ) -o $(NAME_BONUS)
	@echo " $(NAME_BONUS) compiled and ready."

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ): $(HEADER)
$(BOBJ): $(HEADER_BONUS)

clean:
	@rm -f $(OBJ) $(BOBJ)
	@echo "Object files deleted."

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "Executable deleted."

re: fclean all

.PHONY: all clean fclean re bonus