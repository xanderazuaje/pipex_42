/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 04:40:56 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/04/11 16:06:38 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	iterate_pipes(int argc, char **argv, char **env)
{
	int	count;
	int	pipe_fd[3][2];
	int	id;
	int i;

	if (ft_strncmp("here_doc", argv[1], 9) == 0)
		count = 3;
	else
		count = 2;
	i = count;
	while (i < argc - 1)
	{
		pipe(pipe_fd[CURR_PIPE]);
		id = fork();
		if (id == 0)
		{
			if(i == count)
			{
				pipe_fd[FILES][INFILE] = open(argv[1], O_RDONLY);
				first_process(pipe_fd, argv[i], env);
			}
			else if(i == argc - 2)
			{
				pipe_fd[FILES][OUTFILE] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
				last_process(pipe_fd, argv[i], env);
			}
			else
			{
				middle_process(pipe_fd, argv[i], env);
			}
		}
		pipe_fd[PREV_PIPE][RD_PIPE] = pipe_fd[CURR_PIPE][RD_PIPE];
		pipe_fd[PREV_PIPE][WR_PIPE] = pipe_fd[CURR_PIPE][WR_PIPE];
		close(pipe_fd[PREV_PIPE][WR_PIPE]);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	int		state;

	if (!BONUS && argc != 5)
		return (ft_putstr_fd("Program must have 4 parameters", 2), 0);
	if (argc < 5)
		return (ft_putstr_fd("not enough params\n", 2), 0);
	iterate_pipes(argc, argv, env);
	state = 0;
	close(0);
	while (state != -1)
		state = waitpid(-1, NULL, 0);
}
