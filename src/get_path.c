/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:43:29 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/04/07 22:38:04 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *arg, char **env)
{
	char		*path;

	path = find_path(arg, env);
	if (!path)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	return path;
}
