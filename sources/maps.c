/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:52:13 by ioztimur          #+#    #+#             */
/*   Updated: 2023/05/03 04:56:04 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	is_valid_map(t_game *game, int x, int y)
{
	game->map.clone[y][x] = '*';
	if (game->map.clone[y][x - 1] != '1' && game->map.clone[y][x - 1] != '*'
	&& game->map.clone[y][x - 1] != 'E' && game->map.clone[y][x - 1] != 'C')
		is_valid_map(game, x - 1, y);
	if (game->map.clone[y][x + 1] != '1' && game->map.clone[y][x + 1] != '*'
	&& game->map.clone[y][x + 1] != 'E' && game->map.clone[y][x + 1] != 'C')
		is_valid_map(game, x + 1, y);
	if (game->map.clone[y - 1][x] != '1' && game->map.clone[y - 1][x] != '*'
	&& game->map.clone[y - 1][x] != 'E' && game->map.clone[y - 1][x] != 'C')
		is_valid_map(game, x, y - 1);
	if (game->map.clone[y + 1][x] != '1' && game->map.clone[y + 1][x] != '*'
	&& game->map.clone[y + 1][x] != 'E' && game->map.clone[y + 1][x] != 'C')
		is_valid_map(game, x, y + 1);
	else
	{
		game->map.clone[y][x] = '*';
		return ;
	}
}

void	validation(t_game *game, int x, int y)
{
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.clone[y][x] == 'C')
			{
				ft_printf("The map is invalid");
				exit (1);
			}
			if (game->map.clone[y][x] == 'E')
			{
				ft_printf("The map is invalid");
				exit (1);
			}
			x++;
		}
		y++;
	}
}

//To get height and width of the map and check if the map is rectangle
void	ft_countmap(t_game *game)
{
	char	*line;
	int		fd;
	int		check;

	game->map.height = 0;
	fd = open(game->map.path, O_RDONLY);
	line = get_next_line(fd);
	game->map.width = ft_strlen(line) - 1;
	while (line)
	{
		game->map.height++;
		free(line);
		line = get_next_line(fd);
		if (line)
			check = ft_strlen(line) - 1;
		if (check != game->map.width)
		{
			ft_printf("Your map is not rectangular!!");
			exit(1);
		}
	}
	close(fd);
	free(line);
}

//To read the whole map
char	**read_map(t_game *game)
{
	int		fd;
	int		i;
	int		j;
	char	**output;

	ft_countmap(game);
	output = calloc(game->map.height, sizeof(char *));
	fd = open(game->map.path, O_RDONLY);
	i = 0;
	while (i < game->map.height)
	{
		output[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (output);
}
