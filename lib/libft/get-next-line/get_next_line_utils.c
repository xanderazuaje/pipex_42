/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:22:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/08 18:48:56 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memcpy_gnl(void *dst, void *src, size_t n)
{
	char	*dest_aux;
	char	*src_aux;

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

size_t	len_to_nl_gnl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	sub_str = malloc(len + 1);
	if (!sub_str)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	*ft_strdup_gnl(char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
