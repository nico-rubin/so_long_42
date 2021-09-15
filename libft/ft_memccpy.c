/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:00:53 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/18 15:55:32 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies no more than 'n' bytes from memory area 'src' to memory area 'dst',
// stopping when the character 'c' is found.

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ret;
	const unsigned char	*unsigned_src;
	unsigned char		*unsigned_dst;

	i = 0;
	c = (unsigned char)c;
	ret = dst;
	unsigned_dst = (unsigned char *)dst;
	unsigned_src = (const unsigned char *)src;
	while (i < n)
	{
		unsigned_dst[i] = unsigned_src[i];
		if (unsigned_src[i] == c)
			return (&unsigned_dst[i + 1]);
		i++;
	}
	return (NULL);
}
