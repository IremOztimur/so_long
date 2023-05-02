/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:13:24 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/04/30 00:18:34 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//to check the filetype is .ber
void	path_control(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'r' || path[len - 2] != 'e' || \
	path[len - 3 ] != 'b' || path[len - 4] != '.')
	{
		ft_printf("Invalid Map!!");
		exit(1);
	}
}

//to check map is readable
void	file_control(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Invalid Map!!");
		close(fd);
		exit(1);
	}
	close(fd);
}

//to check there is a player
void	player_control(t_game	*game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == 'P')
				game->data.p += 1;
			j++;
		}
		i++;
	}
	if (game->data.p != 1)
	{
		ft_printf("You must have only 1 player!");
		exit_game(game);
	}
}

//to check the map surrounded with the walls
void	wall_control(t_game *game)
{
	//check the rows
	int	i;

	i = 0;
	while (game->map.matrix[0][i++])
	{
		if (game->map.matrix[0][i] != '1' ||
		game->map.matrix[game->map.height - 1][i] != '1')
		{
			ft_printf("The map is invalid !!");
			exit_game(game);
		}
	}
	//check the columns
	i = 0;
	while (game->map.matrix[++i])
	{
		if (game->map.matrix[i][0] != '1' ||
		game->map.matrix[i][game->map.width - 1] != '1')
		{
			ft_printf("The map is invalid !!");
			exit_game(game);
		}
	}
}

//to check there is an exit gate
void	gate_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == 'E')
				game->data.e += 1;
			j++;
		}
		i++;
	}
	if (game->data.e != 1)
	{
		ft_printf("Your map is invalid!!");
		exit_game(game);
	}

}
