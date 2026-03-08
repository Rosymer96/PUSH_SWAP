# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 13:28:09 by albben-a          #+#    #+#              #
#    Updated: 2026/02/26 21:19:34 by albben-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
HEADER  = push_swap.h
CC      = cc
FLAGS   = -Wall -Wextra -Werror

SRC     =	main2.c alg_adaptive.c alg_medium.c alg_simple.c\
			alg_complex_utils.c alg_complex_lis.c alg_complex.c benchmark_utils.c \
			choose_alg.c free_memory.c ft_split.c list_functions.c mov_push.c \
			mov_reverse_rotate.c mov_rotate.c mov_swap.c parser_args.c pos_utils.c \
			process_num.c stack_creator.c utils.c 


OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo " $(NAME) compilado y listo."

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re