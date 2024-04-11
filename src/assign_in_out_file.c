/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_in_out_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:54:49 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/04/07 18:23:27 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	listen_input(const int *pipe_fd, char *limit)
{
	char	*last_line;
	size_t	lim_size;

	lim_size = ft_strlen(limit);
	while (1)
	{
		last_line = get_next_line(STDIN_FILENO);
		if (!last_line || ft_strncmp(limit, last_line, lim_size) == 0)
		{
			close(pipe_fd[1]);
			free(last_line);
			free(limit);
			break ;
		}
		write(pipe_fd[1], last_line, ft_strlen(last_line));
		free(last_line);
	}
}

int	here_doc(char **argv, int pipes[3][2])
{
	int		pipe_fd[2];
	char	*limit;

	limit = ft_strjoin(argv[2], "\n");
	if (!limit)
		return (0);
	if (pipe(pipe_fd) == -1)
		return (0);
	pipes[FILES][RD_PIPE] = pipe_fd[0];
	listen_input(pipe_fd, limit);
	return (1);
}
/*
void	assign_in_out_file(t_cp *cp, char **argv, int argc)
{
	int mode;

	if (BONUS && ft_strncmp(argv[1], "here_doc", 9) == 0 && argc > 5)
	{
		if (!here_doc(argv, cp))
			return;
		mode = O_RDWR | O_CREAT | O_APPEND;
	}
	else
	{
		cp->infile = open(argv[1], O_RDONLY);
		mode = O_RDWR | O_CREAT | O_TRUNC;
	}
	cp->outfile = open(argv[argc - 1], mode, 0644);
}
*/