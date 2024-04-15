/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:55:26 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/04/15 01:04:41 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_error(int pipes[3][2], char *file)
{
	close(pipes[CURR_PIPE][WR_PIPE]);
	close(pipes[CURR_PIPE][RD_PIPE]);
	perror(file);
	exit(0);
}

void	first_process_heredoc(int pipes[3][2], char *arg, char **env)
{
	t_splitted	*args;
	char		*path;

	args = ft_split(arg, ' ');
	if (!args)
	{
		perror("error");
		exit(1);
	}
	path = get_path(args->string[0], env);
	dup2(pipes[CURR_PIPE][WR_PIPE], STDOUT_FILENO);
	close(pipes[CURR_PIPE][WR_PIPE]);
	close(pipes[CURR_PIPE][RD_PIPE]);
	execve(path, args->string, env);
	perror(path);
	exit(0);
}

void	first_process(int pipes[3][2], char *arg, char **env, char *infile)
{
	t_splitted	*args;
	char		*path;

	pipes[FILES][INFILE] = open(infile, O_RDONLY);
	if (pipes[FILES][INFILE] == -1)
		exit_error(pipes, infile);
	args = ft_split(arg, ' ');
	if (!args)
	{
		perror("error");
		exit(1);
	}
	path = get_path(args->string[0], env);
	dup2(pipes[FILES][INFILE], STDIN_FILENO);
	close(pipes[FILES][INFILE]);
	dup2(pipes[CURR_PIPE][WR_PIPE], STDOUT_FILENO);
	close(pipes[CURR_PIPE][WR_PIPE]);
	close(pipes[CURR_PIPE][RD_PIPE]);
	execve(path, args->string, env);
	perror(path);
	exit(0);
}

void	middle_process(int pipes[3][2], char *arg, char **env)
{
	t_splitted	*args;
	char		*path;

	args = ft_split(arg, ' ');
	if (!args)
	{
		perror("error");
		exit(1);
	}
	path = get_path(args->string[0], env);
	dup2(pipes[PREV_PIPE][RD_PIPE], STDIN_FILENO);
	close(pipes[PREV_PIPE][RD_PIPE]);
	dup2(pipes[CURR_PIPE][WR_PIPE], STDOUT_FILENO);
	close(pipes[CURR_PIPE][WR_PIPE]);
	close(pipes[CURR_PIPE][RD_PIPE]);
	execve(path, args->string, env);
	perror(path);
	exit(0);
}

void	last_process(int pipes[3][2], char *arg, char **env, char *outfile)
{
	t_splitted	*args;
	char		*path;

	pipes[FILES][OUTFILE] = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipes[FILES][OUTFILE] == -1)
		exit_error(pipes, outfile);
	args = ft_split(arg, ' ');
	if (!args)
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
	perror(path);
	exit(0);
}
