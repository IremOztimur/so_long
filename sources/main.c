/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:39:58 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/04/30 16:37:30 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
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
	player_control(game);
	wall_control(game);
	gate_control(game);
	trash_control(game);
	char_control(game);
}

int	main(int argc, char **av)
{
	t_game	*game;

	if (argc == 2)
	{
		path_control(av[1]);
		file_control(av[1]);
		init_game(game, av[1]);
		mlx_loop(game->mlx);
	}
}
