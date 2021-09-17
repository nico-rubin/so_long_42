/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:45:11 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/17 17:16:05 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

// Check that there is only one E 
int	check_e(t_list *t_map)
{
	int	i;
	int	j;
	int	e_count;

	i = 1;
	e_count = 0;
	while (i < t_map->height - 1)
	{
		j = 1;
		while (j < t_map->width - 1)
		{
			if (t_map->map[i][j] == 'E')
				e_count++;
			j++;
		}
		i++;
	}
	if (e_count != 1)
		return (-1);
	return (0);
}

// Check that there is only one P
int	check_p(t_list *t_map)
{
	int	i;
	int	j;
	int	p_count;

	i = 1;
	p_count = 0;
	while (i < t_map->height - 1)
	{
		j = 1;
		while (j < t_map->width - 1)
		{
			if (t_map->map[i][j] == 'P')
				p_count++;
			j++;
		}
		i++;
	}
	if (p_count != 1)
		return (-1);
	return (0);
}

// Check that there is at least one C
int	check_c(t_list *t_map)
{
	int	i;
	int	j;
	int	c_count;

	i = 1;
	c_count = 0;
	while (i < t_map->height - 1)
	{
		j = 1;
		while (j < t_map->width - 1)
		{
			if (t_map->map[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	if (c_count == 0)
		return (-1);
	return (0);
}

// Checks that the fd is not a directory and that it is valid.
int	check_fd(char **argv)
{
	int	fd;

	fd = open(argv[1], O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
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