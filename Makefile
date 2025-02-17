NAME = pushswap

CC = cc

CFLAGS  = -Wall -Wextra -Werror

SRCS = sop.c push.c addfront.c addback.c

OBJS = $(SRCS: .c= .o)

HEADER = pushswap.h

all: $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 