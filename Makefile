NAME_CLIENT = client
NAME_SERVER = server

HEADER_DIR = ./includes/minitalk.h

SOURCE_DIR = ./src

LBFT_DIR = ./libs/libft

LBFT_LIB = ${LBFT_DIR}/libft.a

SOURCES_FILES_CLIENT = $(SOURCE_DIR)/client.c
SOURCES_FILES_SERVER = $(SOURCE_DIR)/server.c

RM = @rm -f

CC = @clang

CFLAGS = -Wall -Wextra -Werror

# SOURCES = $(addprefix $(SOURCE_DIR)/, $(SOURCES_FILES))

OBJECTS_CLT = ${SOURCES_FILES_CLIENT:.c=.o}
OBJECTS_SRV = ${SOURCES_FILES_SERVER:.c=.o}

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

all: ${NAME_CLIENT} ${NAME_SERVER} ${HEADER_DIR}

$(NAME_CLIENT): ${LBFT_LIB} ${OBJECTS_CLT}
	${CC} ${CFLAGS} ${OBJECTS_CLT} ${LBFT_LIB} -o ${NAME_CLIENT}
	${MSG1}

$(NAME_SERVER): ${LBFT_LIB} ${OBJECTS_SRV}
	${CC} ${CFLAGS} ${OBJECTS_SRV} ${LBFT_LIB} -o ${NAME_SERVER}
	${MSG1}

${LBFT_LIB}:
	@${MAKE} -C ${LBFT_DIR}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM}	${OBJECTS_CLT} ${OBJECTS_SRV}
	@${MAKE} fclean -C ${LBFT_DIR}
	${MSG2}

fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}
	@${MAKE} fclean -C ${LBFT_DIR}

run:
	${MAKE} && ./so_long.a
	${MSG1}

normiall:
	norminette ${SOURCE_DIR}
	norminette ${HEADER_DIR}

# Regenerate compilation
re: fclean all

# phony will run, independent from the state of the file system, avoid make in files with same name
.PHONY: all clean fclean re
