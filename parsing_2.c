/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:45:11 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/17 12:31:35 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	ft_strfind(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}

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

int	check_fd(char **argv)
{
	int	fd;

	fd = open(argv[1], O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
