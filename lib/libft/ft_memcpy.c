/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:42:55 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/15 19:30:24 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest_aux;
	const char	*src_aux;

	if (!(dst == 0 && src == 0))
	{
		dest_aux = dst;
		src_aux = src;
		while (n--)
		{
			*dest_aux++ = *src_aux++;
		}
	}
	return (dst);
}
