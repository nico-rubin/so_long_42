/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:12:27 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/18 15:56:29 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a pointer to a new string (using malloc(3)) which is a duplicate of
// the string 's1'.

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (len--)
		ret[len] = s1[len];
	return (ret);
}
