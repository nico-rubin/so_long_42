/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:59:24 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/15 12:43:32 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int ft_check_args(int argc, char **argv)
{
    char *p;

    // Check that there is something passed as an argument
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

int main(int argc, char **argv)
{
    ft_check_args(argc, argv);
    
    return (0);
}
