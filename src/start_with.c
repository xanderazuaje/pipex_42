/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_with.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:42:21 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/04/07 04:09:54 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	start_with(const char *str, const char *find)
{
	while (*str && *find)
	{
		if (*str != *find)
			return (0);
		str++;
		find++;
	}
	return (1);
}
