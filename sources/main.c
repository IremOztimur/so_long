/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:39:58 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/04/28 21:18:50 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	end_game(t_game *game)
{
	int		i;

	i = 0;
	mlx_destroy_image(game->mlx, game->texture.chr_curr);
	mlx_destroy_image(game->mlx, game->texture.chr_left);
	mlx_destroy_image(game->mlx, game->texture.chr_right);
	mlx_destroy_image(game->mlx, game->texture.background_img);
	mlx_destroy_image(game->mlx, game->texture.garbage_img);
	mlx_destroy_image(game->mlx, game->texture.gate_img);
	mlx_destroy_image(game->mlx, game->texture.wall_img);

}

void	init_game(t_game *game, char *path)
{
	int		x;
	int		y;
	t_game	win;

	x = 0;
	y = 0;
	win.map.matrix = read_map(path);
	put_img(game, x, y);
}

int	main(int argc, char **av)
{
	t_game	game;

	if (argc == 2)
	{
		path_control(av[1]);
		file_control(av[1]);
		init_game(game, av[1]);
	}
}
