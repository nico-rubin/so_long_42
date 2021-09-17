/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:59:24 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/17 11:55:32 by nrubin           ###   ########.fr       */
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
        return (-1);
    // Needs all lines to be the same width
    while (i < t_map->height)
    {
        if (ft_strlen(t_map->map[0]) != ft_strlen(t_map->map[i]))
            return (-1);
        else
            i++;
    }
    // Since it is a rectangle, set the t_map width the to lenght of the first line.
    t_map->width = ft_strlen(t_map->map[0]);
    return (0);
}


// Check that the sides are 1
int check_sides(t_list *t_map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < t_map->width)
    {
        if (t_map->map[0][i] != '1' || t_map->map[t_map->height - 1][i] != '1')
            return (-1);
        i++;    
    }

    while (j < t_map->height)
    {
        if (t_map->map[j][0] != '1' || t_map->map[j][t_map->width - 1] != '1')
            return (-1);
        j++;
    }
    return (0);
}

// Check that the inside is 0 1 C E or P
int check_inside(t_list *t_map)
{
    int i;
    int j;

    i = 1;
    j = 1;
    while (i < t_map->height - 1)
    {
        j = 1;
        while (j < t_map->width - 1)
        {
            if (t_map->map[i][j] != '1' && t_map->map[i][j] != '0' && t_map->map[i][j] != 'E' && t_map->map[i][j] != 'C' && t_map->map[i][j] != 'P')
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}