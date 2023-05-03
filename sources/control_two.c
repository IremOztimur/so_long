/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:17:36 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/05/03 04:43:52 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	trash_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->data.c = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.matrix[i][j] == 'C')
				game->data.c += 1;
			j++;
		}
		i++;
	}
	if (game->data.c <= 0)
	{
		ft_printf("There should be at least one collectable object!");
		exit_game(game);
	}
}

void	char_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.matrix[i][j] != '1' &&
			game->map.matrix[i][j] != '0' &&
			game->map.matrix[i][j] != 'P' &&
			game->map.matrix[i][j] != 'C' &&
			game->map.matrix[i][j] != 'E')
			{
				ft_printf("This map is invalid!!");
				exit_game(game);
			}
			j++;
		}
		i++;
	}
}
