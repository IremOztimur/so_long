/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:52:13 by ioztimur          #+#    #+#             */
/*   Updated: 2023/04/26 16:26:42 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//To get height and width of the map and check if the map is rectangle
void	ft_countmap(char *path)
{
	char	*line;
	int		fd;
	int		check;
	t_map	game;

	game.height = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	game.width = ft_strlen(line) - 1;
	while (line)
	{
		game.height++;
		free(line);
		line = get_next_line(fd);
		if (line)
			check = ft_strlen(line) - 1;
		if (check != game.width)
		{
			ft_printf("Your map is not rectangular!!");
			exit(1);
		}
	}
	free(line);
}


//To read the whole map
char	**read_map(char *path)
{
	int		fd;
	int		i;
	int		j;
	t_map	game;
	char	**output;

	ft_countmap(path);
	output = calloc(game.height, sizeof(char *));
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < game.height)
	{
		output[i] = get_next_line(fd);
		//To check the line is not empty
		if (output[i][0] == '\n')
		{
			ft_printf("Your map contains empty line!!");
			exit(1);
		}
		i++;
	}
	return (output);
}
