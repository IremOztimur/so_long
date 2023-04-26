#ifndef UTILS_H
#define UTILS_H

#include "./utils/mlx/mlx.h"
#include "./utils/gnl/get_next_line.h"
#include "./utils/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_textures
{
    void	*chr_front;
	void	*chr_back;
	void	*chr_left;
	void	*chr_right;
	void	*chr_cur;
    void    *background_img;
    void    *wall_img;
    void    *gate_img;
    void    *garbage_img;
}   t_textures;

typedef struct s_player
{
    int x;
    int y;
    int steps_taken;
}   t_player;

typedef struct s_data
{
    int P;
    int E;
    int C;
    int finish;
}   t_data;

typedef struct s_map
{
    char    **matrix;
    int width;
    int height;
}   t_map;

typedef struct s_game
{
    t_map   map;
    t_textures texture;
    t_player    player;
    t_data  data;
    void    *mlx;
    void    *win;
    char    *steps_text;
}   t_game;

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_J 38
# define KEY_ESC 53

void file_control(char  *path);
void path_control(char  *path);

#endif