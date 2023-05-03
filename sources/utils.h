/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:41:59 by ioztimur          #+#    #+#             */
/*   Updated: 2023/05/03 02:43:31 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef UTILS_H
# define UTILS_H

# include "../utils/mlx/mlx.h"
# include "../utils/Libraries/lib/libft.h"
# include "../utils/Libraries/gnl/get_next_line.h"
# include "../utils/Libraries/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_textures
{
	void	*chr_left;
	void	*chr_curr;
	void	*chr_right;
	void	*background_img;
	void	*wall_img;
	void	*gate_img;
	void	*garbage_img;
}	t_textures;

typedef struct s_player
{
	int	x;
	int	y;
	int	steps_taken;
}	t_player;

typedef struct s_data
{
	int	p;
	int	e;
	int	c;
	int	finish;
	int	gate_x;
	int	gate_y;
}	t_data;

typedef struct s_map
{
	char	**matrix;
	char	**clone;
	int		width;
	int		height;
	char	*path;
}	t_map;

typedef struct s_game
{
	t_map		map;
	t_textures	texture;
	t_player	player;
	t_data		data;
	int			height;
	int			width;
	void		*mlx;
	void		*win;
	char		*score;
}	t_game;

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_J 38
# define KEY_ESC 53

void	file_control(char *path);
void	path_control(char *path);
char	**read_map(t_game *game);
void	ft_countmap(t_game *game);
void	init_game(t_game *game);
void	put_img(t_game *game, int x, int y);
void	exit_game(t_game *game);
void	player_control(t_game	*game);
void	wall_control(t_game *game);
void	gate_control(t_game *game);
void	trash_control(t_game *game);
void	char_control(t_game *game);
void	is_valid_map(t_game *game, int x, int y);
void	validation(t_game *game, int x, int y);
void	put_render(t_game *game, char c, int x, int y);
void	put_score(t_game *game);
void	render_map(t_game *game);

#endif
