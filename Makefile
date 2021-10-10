NAME = minitalk

HEADER_DIR = ./includes

SOURCE_DIR = ./src

LBFT_DIR = ./libs/libft

LBFT_LIB = ${LBFT_DIR}/libft.a

SOURCES_FILES = client.c server.c

RM = @rm -f

CC = @clang

CFLAGS = -Wall -Wextra -Werror

SOURCES = $(addprefix $(SOURCE_DIR)/, $(SOURCES_FILES))

OBJECTS = ${SOURCES:.c=.o}

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

all: ${NAME}

$(NAME): ${LBFT_LIB} ${OBJECTS} ${MLX_HEADER} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${LBFT_LIB} -o ${NAME}
	${MSG1}

${LBFT_LIB}:
	@${MAKE} -C ${LBFT_DIR}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM}	${OBJECTS} ${OBJECTS_BONUS}
	@${MAKE} fclean -C ${LBFT_DIR}
	${MSG2}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}
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
