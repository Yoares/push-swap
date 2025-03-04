NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME_B = checker

SRCS = sop.c stack_func.c parc.c parc_2.c main.c algo.c algo_2.c op.c get_cost.c

SRCS_B = sop.c stack_func.c parc.c parc_2.c main.c algo.c algo_2.c op.c get_cost.c checker_s/checker_p.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

HEADER = push_swap.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

bonus: $(NAME_B)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(NAME_B): $(OBJS_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_B) -L$(LIBFT_DIR) -lft -o $(NAME_B)

clean:
	rm -f $(OBJS) $(OBJS_B)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_B)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
