/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:48:17 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/24 16:07:03 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Appends string 'src' to the end of 'dst'. It will append at most
// size - strlen(dst) - 1 characters, NUL-terminating the result. The strings
// may not overlap, and the 'dst' string must have enough space for the result.

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = (size_t)ft_strlen(dst);
	s_len = (size_t)ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	i = d_len;
	while (i + 1 < size && src[i - d_len])
	{
		dst[i] = (char)(src[i - d_len]);
		i++;
	}
	dst[i] = '\0';
	return (s_len + d_len);
}
