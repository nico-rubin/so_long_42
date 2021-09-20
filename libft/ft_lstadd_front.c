/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:08:01 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/15 15:41:13 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds the element 'new' to the beginning of the list.

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
