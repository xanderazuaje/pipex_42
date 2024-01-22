/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:09:23 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/15 19:30:33 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	if (n != 0)
	{
		while ((*aux_s1 == *aux_s2) && n-- > 1)
		{
			aux_s1++;
			aux_s2++;
		}
		return ((int)*aux_s1 - *aux_s2);
	}
	return (0);
}
