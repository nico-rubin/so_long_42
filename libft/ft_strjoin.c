/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:02:57 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/18 15:47:37 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a new string which is the result
// of the concatenation of 's1' and 's2'.

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;
	char	*ret;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	ret = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (ret);
}
