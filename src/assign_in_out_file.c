/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_in_out_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:54:49 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/03/26 13:54:29 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	listen_input(const int *pipe_fd, char *limit)
{
	char	*last_line;

	while (1)
	{
		last_line = get_next_line(STDIN_FILENO);
		if (!last_line)
			return (close(pipe_fd[0]), 0);
		if (ft_strncmp(limit, last_line, 9) == 0)
		{
			close(pipe_fd[1]);
			free(last_line);
			free(limit);
			break ;
		}
		write(pipe_fd[1], last_line, ft_strlen(last_line));
		free(last_line);
	}
	return (1);
}

int	here_doc(char **argv, t_cp *cp)
{
	int		pipe_fd[2];
	char	*limit;

	limit = ft_strjoin(argv[2], "\n");
	if (!limit)
		return (0);
	if (pipe(pipe_fd) == -1)
		return (0);
	cp->infile = pipe_fd[0];
	return (listen_input(pipe_fd, limit));
}

int	assign_in_out_file(t_cp *cp, char **argv, int argc)
{
	if (BONUS && ft_strncmp(argv[1], "here_doc", 9) == 0 && argc > 5)
	{
		if (!here_doc(argv, cp))
			return (0);
	}
	else
		cp->infile = open(argv[1], O_RDONLY);
	if (cp->infile < 0)
	{
		return (0);
	}
	cp->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (cp->outfile <= 0)
		return (0);
	return (1);
}
