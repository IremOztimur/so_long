/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:39:58 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/05/03 05:51:56 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

void	init_game(t_game *game)
{
	game->map.matrix = read_map(game);
	game->map.clone = read_map(game);
	put_img(game, 0, 0);
	player_control(game);
	wall_control(game);
	gate_control(game);
	trash_control(game);
	char_control(game);
	is_valid_map(game, game->player.x / 64, game->player.y / 64);
	validation(game, 0, 0);
}

int	main(int argc, char **av)
{
	t_game	*game;

	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_game));
		path_control(av[1]);
		file_control(av[1]);
		game->map.path = av[1];
		init_game(game);
		render_map(game);
		mlx_loop(game->mlx);
	}
	else
		ft_printf("2 arguman gir");
}
