/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:43:29 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/04/19 05:29:48 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_handler(char *og_arg)
{
	ft_putstr_fd(ft_substr(og_arg, 0,
			len_to_char(og_arg, ' ') - 1), 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

char	*get_path(char *arg, char **env, char *og_arg)
{
	char		*path;

	if (!arg)
		error_handler(og_arg);
	path = find_path(arg, env);
	if (!path)
		error_handler(og_arg);
	return (path);
}
