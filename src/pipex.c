/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 04:40:59 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/03/25 04:47:19 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char **env, int i, t_cp *cp)
{
	int		id;

	pipe(cp->pipe);
	id = fork();
	if (id == 0)
		child_process(i, cp, env, argc);
	close(cp->pipe[WR_PIPE]);
	cp->prev_pipe = cp->pipe[RD_PIPE];
	free_splitted(&cp->prg_args);
	free(cp->path);
}
