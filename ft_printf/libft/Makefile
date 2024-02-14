NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
AR = ar rcs
RM = rm -f

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

clean: 
	$(RM) $(OBJECTS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
