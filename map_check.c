/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:59:24 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/16 16:59:15 by nrubin           ###   ########.fr       */
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
int check_map(t_list *t_map)
{
    int i;

    i = 0;
    // Needs at least 3 lines
    if (t_map->height < 3)
    {
        printf("This is not a rectangle (need at least three line)\n");
        return (-1);
    }

    // Needs all lines to be the same width
    while (i < t_map->height)
    {
        if (ft_strlen(t_map->map[0]) != ft_strlen(t_map->map[i]))
        {
            printf("This is not a rectangle (all lines need to be the same lenght)\n");
            return (-1);
        }
        else
            i++;
    }
    // Since it is a rectangle, set the t_map width the to lenght of the first line.
    t_map->width = ft_strlen(t_map->map[0]);
    return (0);
}


// Check that the sides are 1

// Check that the inside is 0 1 C E or P

// Check that there is only one of each E and P