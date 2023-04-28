/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:13:24 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/04/26 15:58:00 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
