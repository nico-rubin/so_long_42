/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:59:24 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/15 15:24:14 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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
    {
        printf("Good job\n");
        return (0);
    }
    else
    {
        printf("Error. Not an accepted file type.\n");
        return (-1);
    }
}


char    **read_map(int fd, char **argv)
{
    char    **map;
    int     i;

    i = 0;
    while (get_next_line(fd, argv))
    {
        map[i] = get_next_line(fd, argv);
        printf("line: %s\ni: %i\n", map[i], i);
        i++;
    }
    return (map);
}


int main(int argc, char **argv)
{
    char    **map;
    int     fd;

    check_args(argc, argv);
    fd = open(argv[1], O_RDONLY);
    map = read_map(fd, argv);

    return (0);
}
