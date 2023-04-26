all:
	gcc -framework Appkit -framework OpenGL -L ./utils/mlx -lmlx deneme.c