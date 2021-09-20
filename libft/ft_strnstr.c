/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:46:23 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/24 16:05:52 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the first occurence of the null-terminated string 'needle' in the
//string 'haystack', where not more than 'len' characters are searched.

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != 0 && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == 0)
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
