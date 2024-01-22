/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:11:19 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/17 01:47:52 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front_i;
	size_t	back_i;
	size_t	len;

	front_i = 0;
	back_i = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, ((char *)s1)[front_i]) && len != 0)
	{
		front_i++;
	}
	while (ft_strchr(set, (((char *)s1)[len - back_i])) && len != 0)
	{
		back_i++;
	}
	return (ft_substr(s1, front_i, (len - front_i - back_i) + 1));
}
