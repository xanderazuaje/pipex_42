/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:53:51 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/14 22:33:35 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	char	*new_arr;
	char	*src_copy;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	new_arr = dst;
	src_copy = (char *)src;
	if (dstsize == 0 || dstsize <= len_dst)
		return (len_src + dstsize);
	while (*new_arr != 0)
		new_arr++;
	while (*src_copy != 0 && i < dstsize - len_dst - 1)
	{
		*new_arr++ = *src_copy++;
		i++;
	}
	*new_arr = 0;
	return (len_dst + len_src);
}
