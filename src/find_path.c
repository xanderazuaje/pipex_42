/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:03:50 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/04/09 01:12:50 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*get_path_route(const char *program, t_splitted **routes)
{
	char	*path;
	char	*prev;
	size_t	i;
	int		status;

	i = 0;
	path = NULL;
	while ((*routes) && i < (*routes)->len)
	{
		prev = ft_strjoin("/", program);
		if (!prev)
			break ;
		path = ft_strjoin((*routes)->string[i], prev);
		free(prev);
		if (!path)
			break ;
		status = access(path, X_OK);
		if (status == 0)
			return (free_splitted(routes), path);
		free(path);
		i++;
	}
	return (free_splitted(routes), NULL);
}

char	*find_path(const char *program, char **env)
{
	t_splitted	*routes;

	if (!program)
		return (NULL);
	if (is_path(program))
		return (ft_strdup(program));
	while (*env)
	{
		if (start_with(*env, "PATH"))
		{
			routes = ft_split(*env + 5, ':');
			if (!routes)
				return (NULL);
		}
		env++;
	}
	return (get_path_route(program, &routes));
}
