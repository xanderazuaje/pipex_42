/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 04:40:59 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/03/25 04:42:47 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char **env, int i, int *id, t_cp *cp)
{
	pipe(cp->pipe);
	id[i - cp->count] = fork();
	if (id[i - cp->count] == 0)
		child_process(i, cp, env, argc);
	close(cp->pipe[WR_PIPE]);
	cp->prev_pipe = cp->pipe[RD_PIPE];
	free_splitted(&cp->prg_args);
	free(cp->path);
}
