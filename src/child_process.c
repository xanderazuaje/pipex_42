/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:55:26 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/04/11 14:42:55 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_process(int pipes[3][2], char *arg, char **env)
{

	t_splitted	*args;
	char		*path;

	args = ft_split(arg, ' ');
	if(!args)
	{
		perror("error");
		exit(1);
	}
	path = get_path(args->string[0], env);
	dup2(pipes[FILES][INFILE], STDIN_FILENO);
	close(pipes[FILES][INFILE]);
	dup2(pipes[CURR_PIPE][WR_PIPE], STDOUT_FILENO);
	close(pipes[CURR_PIPE][WR_PIPE]);
	execve(path, args->string, env);
	exit(0);
}


void	middle_process(int pipes[3][2], char *arg, char **env)
{
	t_splitted	*args;
	char		*path;

	args = ft_split(arg, ' ');
	if(!args)
	{
		perror("error");
		exit(1);
	}
	path = get_path(args->string[0], env);
	dup2(pipes[PREV_PIPE][RD_PIPE], STDIN_FILENO);
	close(pipes[PREV_PIPE][RD_PIPE]);
	dup2(pipes[CURR_PIPE][WR_PIPE], STDOUT_FILENO);
	close(pipes[CURR_PIPE][WR_PIPE]);
	execve(path, args->string, env);
	exit(0);
}

void	last_process(int pipes[3][2], char *arg, char **env)
{
	t_splitted	*args;
	char		*path;

	args = ft_split(arg, ' ');
	if(!args)
	{
		perror("error");
		exit(1);
	}
	path = get_path(args->string[0], env);
	dup2(pipes[PREV_PIPE][RD_PIPE], STDIN_FILENO);
	close(pipes[PREV_PIPE][RD_PIPE]);
	dup2(pipes[FILES][OUTFILE], STDOUT_FILENO);
	close(pipes[FILES][OUTFILE]);
	execve(path, args->string, env);
	exit(0);
}
