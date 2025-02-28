NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = sop.c stack_func.c parc.c parc_2.c main.c algo.c algo_2.c op.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re