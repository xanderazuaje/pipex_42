/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 04:40:56 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/04/16 04:34:32 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_count(char **argv)
{
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
		return (3);
	return (2);
}

static void	iterate_pipes(int argc, char **argv, char **env, int count)
{
	int	fds[3][2];
	int	id;
	int	i;

	i = count;
	while (i < argc - 1)
	{
		if (i != argc - 2)
			pipe(fds[CURR_PIPE]);
		id = fork();
		if (id == 0)
		{
			if (i == count)
				first_process(fds, argv[i], env, argv[count - 1]);
			else if (i == argc - 2)
				last_process(fds, argv[i], env, argv[argc - 1]);
			else
				middle_process(fds, argv[i], env);
		}
		close(fds[CURR_PIPE][WR_PIPE]);
		fds[PREV_PIPE][RD_PIPE] = fds[CURR_PIPE][RD_PIPE];
		i++;
	}
	close(fds[PREV_PIPE][RD_PIPE]);
}

static void	heredoc_iterate_pipes(int argc, char **argv, char **env, int count)
{
	int	fds[3][2];
	int	id;
	int	i;

	i = count;
	while (i < argc - 1)
	{
		if (i != argc - 2)
			pipe(fds[CURR_PIPE]);
		id = fork();
		if (id == 0)
		{
			if (i == count)
				first_process_hd(fds, argv[i], env);
			else if (i == argc - 2)
				last_process_hd(fds, argv[i], env, argv[argc - 1]);
			else
				middle_process(fds, argv[i], env);
		}
		close(fds[CURR_PIPE][WR_PIPE]);
		fds[PREV_PIPE][RD_PIPE] = fds[CURR_PIPE][RD_PIPE];
		i++;
	}
	close(fds[PREV_PIPE][RD_PIPE]);
}

int	main(int argc, char **argv, char **env)
{
	int		state;

	if (!BONUS && argc != 5)
		return (ft_putstr_fd("Program must have 4 parameters", 2), 0);
	if (argc < 5)
		return (ft_putstr_fd("not enough params\n", 2), 0);
	if (get_count(argv) == 3 && argc > 5)
	{
		here_doc(argv);
		heredoc_iterate_pipes(argc, argv, env, 3);
	}
	else
	{
		iterate_pipes(argc, argv, env, 2);
	}
	state = 0;
	close(3);
	close(4);
	while (state != -1)
		state = waitpid(-1, NULL, 0);
}
