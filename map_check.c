/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:59:24 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/16 16:27:40 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

// Counts the number of lines in the map and sets t_map.height
void    get_map_height(int fd, char **map, t_list *t_map)
{
    int i;

    i = 0;
    while (get_next_line(fd, map))
        i++;
    i++;
    t_map->height = i;
}

// Fills t_map.map with the map
void    read_map(int fd, char **map, t_list *t_map)
{
    int i;

    i = 0;
    t_map->map = (char **)malloc(sizeof(t_map->map) * t_map->height);
    while (get_next_line(fd, map) > 0){
        t_map->map[i] = ft_strdup(*map);
        i++;
    }
    t_map->map[i] = ft_strdup(*map);
}

// Check that it is a rectangle

// Check that the sides are 1

// Check that the inside is 0 1 C E or P

// Check that there is only one of each E and P