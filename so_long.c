/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:39:58 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/04/25 19:35:21 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


int main(int argc, char **av)
{
    t_game  game;

    if (argc == 2)
    {
        path_control(av[1]);
        file_control(av[1]);
        
    }
    
}