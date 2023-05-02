/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:17:36 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/04/30 16:36:56 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	trash_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i++])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == 'C')
				game->data.c += 1;
			j++;
		}
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
	while (game->map.matrix[i++])
	{
		j = 0;
		while (game->map.matrix[i][j])
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
	}
}
