/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:39:04 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/24 17:59:05 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the amount of words the string 's' will be split in to.

int	ft_word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

// Returns a pointer to a new string which is the duplicate of the string 's'
// up to 'c' characters.

char	*ft_strdupn(const char *s, char c)
{
	char	*ret;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = 0;
	while (len--)
		ret[len] = s[len];
	return (ret);
}

// Frees the array and the strings it contains in the case of a failing
// malloc(3).

void	*ft_free_tab(char **tab, int n)
{
	n = n - 1;
	while (tab[n])
		free(tab[n--]);
	free(tab);
	return (tab);
}

// Workaround for the line number limit.

int	ft_fill(int *i, int *j, const char *s, char *c)
{
	*i = 0;
	*j = 0;
	return (ft_word_count(s, *c));
}

// Allocates (with malloc(3)) and returns an array of strings obtained by
// splitting 's' using the character 'c' as a delimiter. The array must be ended
// by a NULL pointer.

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		count;

	count = ft_fill(&i, &j, s, &c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	while (count--)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[j] = ft_strdupn(&s[i], c);
			if (!tab[j])
				return (ft_free_tab(tab, j));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	tab[j] = 0;
	return (tab);
}
