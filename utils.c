/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:14:50 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/17 17:21:06 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

// Returns 1 at first occurence of the character 'c' in the string
// 's', or 0 if 'c' is not found.
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

// Initialize map structure
t_list	map_init(void)
{
	t_list	t_map;

	t_map.map = NULL;
	t_map.height = 0;
	t_map.width = 0;
	return (t_map);
}

// Free map structure
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
