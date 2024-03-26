/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:43:29 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/03/26 01:42:26 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	set_path(t_splitted **prg_args, char *arg, t_cp *cp, char **env)
{
	*prg_args = ft_split(arg, ' ');
	cp->path = find_path((*prg_args)->string[0], env);
	if (!cp->path)
	{
		ft_putstr_fd(*(*prg_args)->string, 1);
		ft_putstr_fd(": command not found\n", 1);
		return (0);
	}
	return (1);
}
