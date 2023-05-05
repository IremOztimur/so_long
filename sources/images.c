/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:25:14 by ioztimur          #+#    #+#             */
/*   Updated: 2023/05/05 17:16:20 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	put_img(t_game *game, int x, int y)
{
	game->height = game->map.height * 64;
	game->width = game->map.width * 64;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, \
	game->height, "sO L_ONG");
	game->player.x = 0;
	game->player.y = 0;
	game->texture.chr_right = mlx_xpm_file_to_image(game->mlx, \
	"images/player_right.xpm", &x, &y);
	game->texture.chr_left = mlx_xpm_file_to_image(game->mlx, \
	"images/player_left.xpm", &x, &y);
	game->texture.chr_curr = game->texture.chr_right;
	game->texture.background_img = mlx_xpm_file_to_image(game->mlx, \
	"images/background.xpm", &x, &y);
	game->texture.gate_img = mlx_xpm_file_to_image(game->mlx, \
	"images/exit.xpm", &x, &y);
	game->texture.wall_img = mlx_xpm_file_to_image(game->mlx, \
	"images/grass.xpm", &x, &y);
	game->texture.garbage_img = mlx_xpm_file_to_image(game->mlx, \
	"images/trash.xpm", &x, &y);
}

void	put_render(t_game *game, char c, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->texture.background_img, x, y);
	if (c == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->texture.wall_img, x, y);
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->texture.chr_curr, x, y);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->texture.garbage_img, x, y);
	}
	if (c == 'E')
	{
		game->data.gate_x = x;
		game->data.gate_y = y;
		mlx_put_image_to_window(game->mlx, game->win, \
		game->texture.gate_img, x, y);
	}
}

void	put_score(t_game *game)
{
	game->score = ft_itoa(game->player.steps_taken);
	mlx_string_put(game->mlx, game->win, 20, 20, 0xFFFFFFFF, game->score);
}

void	render_map(t_game *game)
{
	int	i;
	int	y;
	int	j;
	int	x;

	i = 0;
	y = 0;
	mlx_clear_window(game->mlx, game->win);
	while (i < game->map.height)
	{
		j = 0;
		x = 0;
		while (j < game->map.width)
		{
			put_render(game, game->map.matrix[i][j], x, y);
			put_score(game);
			x += 64;
			j++;
		}
		i++;
		y += 64;
	}
}
