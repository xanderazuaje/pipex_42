/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:17:16 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/16 20:21:33 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	new_len;
	size_t	i;

	if (start + len >= ft_strlen(s))
		new_len = ft_strlen(s) - start + 1;
	else
		new_len = len + 1;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub_str = malloc(new_len);
	if (!sub_str)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = 0;
	return (sub_str);
}
