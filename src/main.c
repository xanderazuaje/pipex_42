/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 04:40:56 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/03/26 03:26:01 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	reset_pipes(t_cp *cp)
{
	close((*cp).pipe[RD_PIPE]);
	close((*cp).pipe[WR_PIPE]);
	close((*cp).prev_pipe);
	pipe((*cp).pipe);
	close((*cp).pipe[WR_PIPE]);
	(*cp).prev_pipe = (*cp).pipe[RD_PIPE];
}

static void	finish_pipes(t_cp *cp)
{
	close((*cp).pipe[RD_PIPE]);
	close((*cp).pipe[WR_PIPE]);
	close((*cp).infile);
	close((*cp).outfile);
}

static int	get_first_command(char **argv)
{
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
		return (3);
	return (2);
}

void	iterate_pipes(int argc, char *const *argv, char **env, t_cp *cp)
{
	int	i;

	i = (*cp).count;
	while (i < argc - 1)
	{
		if (!set_path(&(*cp).prg_args, argv[i], cp, env) && i++)
		{
			reset_pipes(cp);
			continue ;
		}
		pipex(argc, env, i, cp);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_cp	cp;
	int		state;

	if (!BONUS && argc != 5)
		return (ft_putstr_fd("Program must have 4 parameters", 2), 0);
	if (!check_input(argc, argv, &cp))
		return (0);
	cp.count = get_first_command(argv);
	iterate_pipes(argc, argv, env, &cp);
	state = 0;
	finish_pipes(&cp);
	while (state != -1)
		state = waitpid(-1, NULL, 0);
}
