/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:44:35 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/18 15:56:06 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies 'n' bytes from memory area 'src' to memory area 'dst'. The memory
// areas may overlap.

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*u_dst;
	const unsigned char	*u_src;

	u_dst = (unsigned char *)dst;
	u_src = (const unsigned char *)src;
	if (dst > src)
	{
		while (n--)
		{
			u_dst[n] = u_src[n];
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, n));
}
