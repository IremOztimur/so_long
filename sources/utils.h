/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:41:59 by ioztimur          #+#    #+#             */
/*   Updated: 2023/04/28 21:05:15 by ioztimur         ###   ########.fr       */
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
}	t_data;

typedef struct s_map
{
	char	**matrix;
	int		width;
	int		height;
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
	char		*steps_text;
}	t_game;

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_J 38
# define KEY_ESC 53

void	file_control(char *path);
void	path_control(char *path);
char	**read_map(char *path);
void	ft_countmap(char *path);
void	init_game(t_game *game, char *path);
void	put_img(t_game *game, int x, int y);

#endif
