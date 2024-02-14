
NAME = push_swap
CC	=	cc
CFLAGS = -Wall -Wextra -Werror  
ALL_SRCS = $(wildcard ./project/*.c)
OBJS = $(patsubst %.c, %.o, $(ALL_SRCS))
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re 
