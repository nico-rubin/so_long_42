/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:22:30 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/18 15:55:51 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies 'n' bytes from memory area 'src' to memory area 'dst'. The memory
// areas must not overlap.

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t				i;
	unsigned char		*ret;
	const unsigned char	*unsigned_src;
	unsigned char		*unsigned_dst;

	i = 0;
	ret = dst;
	unsigned_dst = (unsigned char *)dst;
	unsigned_src = (const unsigned char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (i < n)
	{
		unsigned_dst[i] = unsigned_src[i];
		i++;
	}
	return (ret);
}
