/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:06:53 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/16 16:25:13 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

typedef struct s_list
{
    char    **map;
    int     height;
    int     width;
}              t_list;

void    get_map_height(int fd, char **map, t_list *t_map);
void    read_map(int fd, char **map, t_list *t_map);

#endif


