/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:17:36 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/05/05 20:28:44 by ioztimur         ###   ########.fr       */
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

void	map_control(t_game *game)
{
	int		fd;
	char	*buffer;
	size_t	value;

	buffer = malloc(sizeof(char) * 100);
	fd = open(game->map.path, O_RDONLY);
	value = read(fd, buffer, 100);
	if (value <= 0 || value == '\0')
	{
		ft_printf("The map is invalid!");
		close(fd);
		exit (1);
	}
	close(fd);
}
