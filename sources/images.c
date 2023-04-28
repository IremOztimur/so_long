/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:25:14 by ioztimur          #+#    #+#             */
/*   Updated: 2023/04/28 21:24:52 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//malloc problemini çöz
void	put_img(t_game *game, int x, int y)
{
	game->height = game->map.height * 64;
	game->width = game->map.width * 64;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width,\
	game->height, "sO L_ONG");
	game->player.x = 0;
	game->player.y = 0;
	game->texture = malloc(sizeof(t_textures));
	game->texture.chr_right = mlx_xpm_file_to_image(game->mlx, "", &x, &y);
	game->texture.chr_left = mlx_xpm_file_to_image(game->mlx, "", &x, &y);
	game->texture.chr_curr = game->texture.chr_right;
	game->texture.background_img = mlx_xpm_file_to_image(game->mlx, "", &x, &y);
	game->texture.gate_img = mlx_xpm_file_to_image(game->mlx, "", &x, &y);
	game->texture.wall_img = mlx_xpm_file_to_image(game->mlx, "", &x, &y);
	game->texture.garbage_img = mlx_xpm_file_to_image(game->mlx, "", &x, &y);
}
