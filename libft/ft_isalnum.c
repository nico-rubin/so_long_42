/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:49:46 by nrubin            #+#    #+#             */
/*   Updated: 2021/05/15 15:56:00 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Tests whether 'c' is a character of class alpha or digit.

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
