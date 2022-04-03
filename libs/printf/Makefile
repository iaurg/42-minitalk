NAME = libftprintf.a

LIBFT_DIR	= ./libft

LIBFT		= ${LIBFT_DIR}/libft.a

HEADER_DIR = ./header

INCLUDES = -I${HEADER_DIR} -I${LIBFT_DIR}

SOURCE_DIR = ./src

SOURCES = $(SOURCE_DIR)/ft_printf.c
SOURCES += $(SOURCE_DIR)/ft_parse_flag.c
SOURCES += $(SOURCE_DIR)/ft_printf_c.c
SOURCES += $(SOURCE_DIR)/ft_printf_s.c
SOURCES += $(SOURCE_DIR)/ft_printf_p.c
SOURCES += $(SOURCE_DIR)/ft_printf_d.c
SOURCES += $(SOURCE_DIR)/ft_printf_i.c
SOURCES += $(SOURCE_DIR)/ft_printf_u.c
SOURCES += $(SOURCE_DIR)/ft_printf_x.c

RM = @rm -f

RANLIB = @ranlib

ARCHIVE = @ar -rc

CC = @clang

CFLAGS = -Wall -Wextra -Werror

OBJECTS = ${SOURCES:.c=.o}

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

# Mandatory
all: ${NAME}

# Mandatory
$(NAME): ${OBJECTS} ${LIBFT}
	${ARCHIVE} ${NAME} ${OBJECTS}
	${RANLIB} ${NAME}
	${MSG1}

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${LIBFT}:
			make -C ${LIBFT_DIR}
			cp ${LIBFT} ${NAME}

# Mandatory
clean:
	make clean -C ${LIBFT_DIR}
	${RM}	${OBJECTS}
	${MSG2}

# Mandatory
fclean: clean
	make fclean -C ${LIBFT_DIR}
	${RM} ${NAME}

# Mandatory
# Regenarate compilation
re: fclean all

# phony will run, independent from the state of the file system, avoid make in files with same name
.PHONY: all clean fclean re
