/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:04:05 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/18 16:04:27 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Erases the data in the 'n' bytes of memory starting at the location pointed
// to by 's', by writing zeros (bytes containing '\0') to that are.

void	ft_bzero(void *s, size_t n)
{
	int	c;

	c = '\0';
	if (n == 0)
		return ;
	ft_memset(s, c, n);
	return ;
}
