/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 05:34:34 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/03/26 02:31:05 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BONUS
#  define BONUS 0
# endif
# define WR_PIPE 1
# define RD_PIPE 0

# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cp
{
	char		*path;
	int			infile;
	int			outfile;
	int			prev_pipe;
	int			pipe[2];
	int			count;
	int			argc;
	t_splitted	*prg_args;
}				t_cp;

int				start_with(const char *str, const char *find);
void			free_splitted(t_splitted **s);
int				is_path(const char *str);
char			*find_path(const char *program, char **env);
int				assign_in_out_file(t_cp *cp, char **argv, int argc);
int				check_input(int argc, char **argv, t_cp *cp);
int				set_path(t_splitted **prg_args, char *arg, t_cp *cp,
					char **env);
void			child_process(int i, t_cp *cp, char **env, int argc);
void			pipex(int argc, char **env, int i, t_cp *cp);
#endif
