/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:55:26 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/03/25 03:55:29 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int i, t_cp *cp, char **env, int argc)
{
	if (i == cp->count)
	{
		dup2(cp->infile, STDIN_FILENO);
		close(cp->infile);
	}
	else
	{
		dup2(cp->prev_pipe, STDIN_FILENO);
		close(cp->prev_pipe);
	}
	if (i != argc - 2)
	{
		dup2(cp->pipe[WR_PIPE], STDOUT_FILENO);
		close(cp->pipe[WR_PIPE]);
	}
	else
	{
		dup2(cp->outfile, STDOUT_FILENO);
		close(cp->outfile);
	}
	execve(cp->path, cp->prg_args->string, env);
	exit(1);
}
