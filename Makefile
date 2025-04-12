#______________VARIABLES :____________________

NAME = push_swap

SRCS = main.c				\
	ft_push_swap_utils.c	\
	ft_instructions.c		\
	ft_push_swap_sort.c		\
	ft_quick_sort_init.c	\
	ft_instructions_part2.c	\
	ft_instructions_part3.c	\
	ft_instructions_part4.c	\
	ft_sort_three.c			\
	ft_ERROR.c				\
	ft_push_swap_split.c	\
	ft_intializer_part1.c	\
	ft_intializer_part2.c	\

OBJ = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
