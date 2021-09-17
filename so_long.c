/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:59:24 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/17 17:05:32 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

// Initialize map structure
t_list	map_init(void)
{
	t_list	t_map;

	t_map.map = NULL;
	t_map.height = 0;
	t_map.width = 0;
	return (t_map);
}

// Check that the correct number of arguments are passed
// to the function and that the argument is of correct type
int	check_args(int argc, char **argv)
{
	char	*p;

	if (argc != 2)
		return (-1);
	if (!ft_strfind(argv[1], '.'))
		return (-1);
	p = ft_strchr(argv[1], '.');
	if (p[1] == 'b' && p[2] == 'e' && p[3] == 'r' && p[4] == '\0')
		return (0);
	else
		return (-1);
}

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

void	free_map(t_list *t_map)
{
	int	i;

	i = 0;
	while (i < t_map->height)
	{
		free(t_map->map[i]);
		i++;
	}
	free(t_map->map);
}

int	main(int argc, char **argv)
{
	t_list	t_map;
	char	*ret[BUFFER_GNL + 1];
	int		fd;
	int		j;

	j = 0;
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
	get_map_height(fd, ret, &t_map);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	read_map(fd, ret, &t_map);
	close(fd);
	if (check_map(t_map) == -1)
		printf("Error\nMap error.\n");
	free_map(&t_map);
	return (0);
}
