NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = sop.c push.c addfront.c addback.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

LIBFT_A = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@cd libft && make && make clean
	$(CC) $(CFLAGS) -L./libft -lft $(OBJS) $(LIBFT_A) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re