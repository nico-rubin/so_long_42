/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:05:57 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/15 15:58:29 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compares the first 'n' bytes of the memory areas 's1' and 's2'.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*unsigned_s1;
	unsigned char	*unsigned_s2;

	i = 0;
	unsigned_s1 = (unsigned char *)s1;
	unsigned_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((unsigned_s1[i] == unsigned_s2[i]) && i + 1 < n)
		i++;
	return (unsigned_s1[i] - unsigned_s2[i]);
}
