/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:29:16 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/15 19:30:18 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest_aux;
	const char	*src_aux;

	dest_aux = dst;
	src_aux = src;
	if (dst != 0 || src != 0)
	{
		if (dest_aux < src_aux)
		{
			while (len--)
			{
				*dest_aux++ = *src_aux++;
			}
		}
		else
		{
			while (len--)
			{
				dest_aux[len] = src_aux[len];
			}
		}
	}
	return (dst);
}
