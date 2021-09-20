/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:07:01 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/18 15:55:42 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Scans the initial 'n' bytes of the memory area pointed to by 's' for the
// first instance of 'c'.

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*unsigned_s;

	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		unsigned_s = s;
		if (*unsigned_s == c)
			return ((void *)unsigned_s);
		i++;
		s++;
	}
	return (NULL);
}
