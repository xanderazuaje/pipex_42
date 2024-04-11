/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 05:34:34 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/04/11 13:06:08 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BONUS
#  define BONUS 0
# endif
# define WR_PIPE 1
# define RD_PIPE 0
# define FILES 0
# define INFILE 0
# define OUTFILE 1
# define CURR_PIPE 1
# define PREV_PIPE 2

# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

int				start_with(const char *str, const char *find);
void			free_splitted(t_splitted **s);
int				is_path(const char *str);
char			*find_path(const char *program, char **env);
char			*get_path(char *arg, char **env);
void			middle_process(int pipes[3][2], char *argv, char **env);
void			first_process(int pipes[3][2], char *arg, char **env);
void			last_process(int pipes[3][2], char *arg, char **env);
#endif
