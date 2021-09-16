/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:59:24 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/16 14:01:01 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

// Initialize map structure
t_list map_init(void)
{
    t_list map;
    
    map.map = NULL;
    map.height = 0;
    map.width = 0;
    return (map);
}

// Check that the correct number of arguments are passed to the function and that the argument is of correct type
int check_args(int argc, char **argv)
{
    char *p;

    // Check the number of arguments
    if (argc != 2)
    {
        printf("Error. Enter only one argument.\n");
        return (-1);
    }
    // Check that it is a file
    if (!ft_strchr(argv[1], '.'))
    {
        printf("Error. Not a file.\n");
        return (-1);
    }
    // Check that it is a .ber
    p = ft_strchr(argv[1], '.');
    if (p[1] == 'b' && p[2] == 'e' && p[3] == 'r' && p[4] == '\0')
        return (0);
    else
    {
        printf("Error. Not an accepted file type.\n");
        return (-1);
    }
}


void    read_map(int fd, char **line, t_list *t_map)
{
    int i;

    i = 0;
    t_map->height = 0;
    while (get_next_line(fd, line))
    {
        printf("%s\n", *line);
        //t_map->map[i] = ft_strdup(*line);
        //i++;
    }
    printf("%s\n", *line);
    //t_map->map[i] = ft_strdup(*line);
}


int main(int argc, char **argv)
{
    char    **line;
    t_list  t_map;
    int     fd;

    line = NULL;
    t_map = map_init();
    check_args(argc, argv);
    fd = open(argv[1], O_RDONLY);
    read_map(fd, line, &t_map);

    return (0);
}
