NAME    = push_swap
HEADER  = push_swap.h
CC      = cc
FLAGS   = -Wall -Wextra -Werror

SRC     = main.c parser.c validation.c utils_memory.c \
          ft_split.c moves_push.c moves_rev_rotate.c \
          moves_rotate.c moves_swap.c sort_algorithm.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo " $(NAME) compilado y listo."

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo " Objetos eliminados."

fclean: clean
	@rm -f $(NAME)
	@echo " $(NAME) eliminado."

re: fclean all

.PHONY: all clean fclean re