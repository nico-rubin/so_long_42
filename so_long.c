/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:59:24 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/16 16:55:05 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

// Initialize map structure
t_list map_init(void)
{
    t_list t_map;

    t_map.map = NULL;
    t_map.height = 0;
    t_map.width = 0;

    return (t_map);
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

int main(int argc, char **argv)
{
    t_list  t_map;
    int     fd;

    t_map = map_init();
    check_args(argc, argv);
    fd = open(argv[1], O_RDONLY);
    get_map_height(fd, argv, &t_map);
    close(fd);
    fd = open(argv[1], O_RDONLY);
    read_map(fd, argv, &t_map);
    close(fd);
    if (check_map(&t_map) == -1)
        return (0); 
    // TESTING
    int     i;

    i = 0;
    while (i < t_map.height)
        printf("%s\n", t_map.map[i++]);
    // END TEST
    return (0);
}
