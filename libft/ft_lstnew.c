/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:50:19 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/24 16:05:36 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a new element. The varaible 'content'
// is initialized with the value of the parameter 'content'. The variable 'next'
// is initialized to NULL.

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
