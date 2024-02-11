NAME        = server client
NAME_BONUS  = server_bonus client_bonus
SRC         = client.c server.c utils.c
SRC_BONUS   = client_bonus.c server_bonus.c utils.c
OBJ         = ${SRC:.c=.o}
OBJ_BONUS   = ${SRC_BONUS:.c=.o}
RM          = rm -f
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

RED         = "\033[0;31m"
GREEN       = "\033[0;32m"
YELLOW      = "\033[0;33m"

all: ${NAME}

${NAME}: ${OBJ}
	@echo ${GREEN}
	${CC} ${CFLAGS} server.o utils.o -o server
	${CC} ${CFLAGS} client.o utils.o -o client

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJ_BONUS}
	@echo ${YELLOW}
	${CC} ${CFLAGS} server_bonus.o utils.o -o server_bonus
	${CC} ${CFLAGS} client_bonus.o utils.o -o client_bonus

clean:
	@echo ${RED}
	${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all bonus clean fclean re
