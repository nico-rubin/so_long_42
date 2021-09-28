/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:59:24 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/28 13:20:30 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

// Send map to check functions
int	check_map(t_list t_map)
{
	if (check_size(&t_map) == -1)
		return (-1);
	if (check_sides(&t_map) == -1)
		return (-1);
	if (check_inside(&t_map) == -1)
		return (-1);
	if (check_e(&t_map) == -1)
		return (-1);
	if (check_p(&t_map) == -1)
		return (-1);
	if (check_c(&t_map) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	t_map;
	int		fd;

	t_map = map_init();
	if (check_args(argc, argv) == -1)
	{
		printf("Error\nArgument error.\n");
		return (-1);
	}
	if (check_fd(argv) == 0)
		fd = open(argv[1], O_RDONLY);
	else
	{
		printf("Error\nFile Descriptor error.\n");
		return (-1);
	}
	get_map_height(fd, argv, &t_map);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	read_map(fd, argv, &t_map);
	close(fd);
	if (check_map(t_map) == -1)
	{
		printf("Error\nMap error.\n");
		free_map(&t_map);
		return (0);
	}
	// START OF TEST //
	int i = 0;
	while (i < t_map.height)
	{
		printf("%s\n", t_map.map[i]);
		i++;
	}
	// END OF TEST //
	free_map(&t_map);
	return (0);
}
