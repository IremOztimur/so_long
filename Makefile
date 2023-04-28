NAME = so_long
CFLAGS = -Wall -Wextra -Werror -I./utils/mlx -g
MFLAGS = -framework Appkit -framework OpenGL -L ./utils/mlx -lmlx
MLX = ./utils/mlx/libmlx.a
LIB = ./utils/Libraries/utils.a
SRCS = sources/main.c \
		sources/control.c \
		sources/maps.c

all: ${MLX} ${NAME}

${NAME}: ${SRCS} ${MLX} ${LIB}
		@gcc -g ${MFLAGS} ${SRCS} ${LIB} -o ${NAME}

${MLX}:
	@make -C ./utils/mlx

${LIB}:
	@make -C ./utils/Libraries

clean:
	@rm -fr ${NAME}

fclean: clean
	@${RM} ${NAME}
	@make -C ./utils/Libraries fclean

re: clean all

.PHONY: clean re
