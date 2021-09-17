/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:06:53 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/17 17:17:44 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

typedef struct s_list
{
	char	**map;
	int		height;
	int		width;
}				t_list;

void	get_map_height(int fd, char **map, t_list *t_map);
void	read_map(int fd, char **map, t_list *t_map);
int		check_size(t_list *t_map);
int		check_sides(t_list *t_map);
int		check_inside(t_list *t_map);
int		check_e(t_list *t_map);
int		check_p(t_list *t_map);
int		check_c(t_list *t_map);
int		ft_strfind(const char *s, int c);
void	free_map(t_list *t_map);
int		check_fd(char **argv);
int		check_args(int argc, char **argv);
t_list	map_init(void);


#endif