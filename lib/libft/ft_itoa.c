/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:58:20 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:19:40 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	get_digits(int n)
{
	int		i;
	long	n2;

	i = 0;
	n2 = (long)n;
	if (n2 < 0)
		n2 *= -1;
	while (n2 >= 10)
	{
		n2 /= 10;
		i++;
	}
	return (++i);
}

char	*ft_itoa(int n)
{
	int		digits;
	long	n2;
	char	*str;

	digits = get_digits(n);
	n2 = (long)n;
	if (n < 0)
	{
		digits++;
		n2 *= -1;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (0);
	str[digits] = 0;
	while (n2 >= 10)
	{
		str[--digits] = (char)((n2 % 10) + '0');
		n2 /= 10;
	}
	str[--digits] = (char)((n2 % 10) + '0');
	if (n < 0)
		str[--digits] = '-';
	return (str);
}
