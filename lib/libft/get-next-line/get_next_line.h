/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:12:31 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/08 19:09:05 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

typedef struct t_Tuple
{
	char	*line;
	char	*remain;
}			t_Tuple;
char		*get_next_line(int fd);
char		*ft_substr_gnl(char *s, unsigned int start, size_t len);
size_t		len_to_nl_gnl(char *s);
char		*ft_strdup_gnl(char *s);
char		*ft_strjoin_gnl(char *rest, char *str_buffer);
void		*ft_memcpy_gnl(void *dst, void *src, size_t n);
t_Tuple		dvd(char *s);

#endif
