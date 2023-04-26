/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:21:15 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/04/25 20:47:00 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void    ft_countmap(char *path)
{
    
}

char    **read_map(char *path)
{
    int fd;
    int i;
    int j;
    t_map game;
    char    **output;
    
    ft_countmap(path);
    output = calloc(game.height, sizeof(char *));
    fd = open(path, O_RDONLY);
    i = 0;
    while(i < game.height)
    {
        output[i] = get_next_line(fd);
        //write a function that checks whether the line is new line
        i++;
    }
    return (output);
}