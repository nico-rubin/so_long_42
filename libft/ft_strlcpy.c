/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:50:53 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/18 15:57:05 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies up to 'dstsize' - 1 characters from the string 'src' to 'dst',
// NUL-terminating the result if 'dstsize' is not 0.

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	count;
	size_t	i;

	count = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (count);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
