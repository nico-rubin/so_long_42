/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:13:07 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/15 16:02:14 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Fills the first 'len' bytes of the memory areas pointed to by 'b' with the
// constant byte 'c'.

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ret;

	ret = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*ret = (unsigned char)c;
		ret++;
		i++;
	}
	return (b);
}
