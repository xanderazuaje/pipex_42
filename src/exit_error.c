/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xander <xander@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 04:47:10 by xander            #+#    #+#             */
/*   Updated: 2024/04/16 04:48:23 by xander           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(int pipes[3][2], char *file)
{
	perror(file);
	close(pipes[CURR_PIPE][WR_PIPE]);
	close(pipes[CURR_PIPE][RD_PIPE]);
	exit(0);
}
