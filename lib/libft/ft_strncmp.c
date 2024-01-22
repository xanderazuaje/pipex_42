/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:16:34 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/15 18:09:15 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n != 0)
	{
		while (*s1 && (*s1 == *s2) && n-- > 1)
		{
			s1++;
			s2++;
		}
		return (((unsigned char)*s1) - ((unsigned char)*s2));
	}
	return (0);
}
