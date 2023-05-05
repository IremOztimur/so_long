/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionality.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:03:34 by ioztimur          #+#    #+#             */
/*   Updated: 2023/05/05 19:48:39 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	change_side(t_game *game, int keycode)
{
	if (keycode == KEY_A)
		game->texture.chr_curr = game->texture.chr_left;
	if (keycode == KEY_D)
		game->texture.chr_curr = game->texture.chr_right;
}

void	print_score(t_game *game)
{
	ft_printf("%d\n", game->player.steps_taken);
}

void	move_player(t_game *game, int key, int x, int y)
{
	if (game->data.c == 0 && game->map.matrix[y / 64][x / 64] == 'E')
	{
		game->player.steps_taken += 1;
		print_score(game);
		ft_printf("You saved the world by collecting all the garbages!");
		exit_game(game);
	}
	if (game->map.matrix[y / 64][x / 64] != '1')
	{
		change_side(game, key);
		game->player.steps_taken += 1;
		if (game->map.matrix[y / 64][x / 64] == 'C')
			game->data.c -= 1;
		game->map.matrix[game->player.y / 64][game->player.x / 64] = '0';
		if (game->map.matrix[y / 64][x / 64] == 'E')
		{
			game->map.matrix[game->player.y / 64][game->player.x / 64] = 'E';
		}
		game->map.matrix[y / 64][x / 64] = 'P';
		game->player.x = x;
		game->player.y = y;
		print_score(game);
	}
}

int	walk(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		move_player(game, keycode, game->player.x - 64, game->player.y);
	if (keycode == KEY_D)
		move_player(game, keycode, game->player.x + 64, game->player.y);
	if (keycode == KEY_S)
		move_player(game, keycode, game->player.x, game->player.y + 64);
	if (keycode == KEY_W)
		move_player(game, keycode, game->player.x, game->player.y - 64);
	if (keycode == KEY_ESC)
		exit_game(game);
	render_map(game);
	return (keycode);
}
