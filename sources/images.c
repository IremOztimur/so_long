/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:25:14 by ioztimur          #+#    #+#             */
/*   Updated: 2023/04/29 17:42:14 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	put_img(t_game *game, int x, int y)
{
	game->height = game->map.height * 64;
	game->width = game->map.width * 64;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width,\
	game->height, "sO L_ONG");
	game->player.x = 0;
	game->player.y = 0;
	game->texture.chr_right = mlx_xpm_file_to_image(game->mlx, "../images/player_right.xpm", &x, &y);
	game->texture.chr_left = mlx_xpm_file_to_image(game->mlx, "../images/player_left.xpm", &x, &y);
	game->texture.chr_curr = game->texture.chr_right;
	game->texture.background_img = mlx_xpm_file_to_image(game->mlx, "../images/background.xpm", &x, &y);
	game->texture.gate_img = mlx_xpm_file_to_image(game->mlx, "../images/exit.xpm", &x, &y);
	game->texture.wall_img = mlx_xpm_file_to_image(game->mlx, "../images/grass.xpm", &x, &y);
	game->texture.garbage_img = mlx_xpm_file_to_image(game->mlx, "../images/trash.xpm", &x, &y);
}
