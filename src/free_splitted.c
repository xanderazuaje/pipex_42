/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splitted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:10:50 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/03/13 17:10:50 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_splitted(t_splitted **s)
{
	if (!*s)
		return ;
	while ((*s)->len)
	{
		free((*s)->string[(*s)->len - 1]);
		(*s)->len--;
	}
	free((*s)->string);
	free(*s);
}
