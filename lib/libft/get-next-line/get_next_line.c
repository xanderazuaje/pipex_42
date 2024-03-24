/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:12:29 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/09 11:09:15 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*size_handler(ssize_t size, char **rst, t_Tuple *rtn)
{
	if (size < 0)
		return (free(*rst), *rst = NULL, NULL);
	if (size == 0)
	{
		if (*rst)
			return (rtn->line = ft_strdup_gnl(*rst), free(*rst), *rst = NULL,
				rtn->line);
		return (NULL);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		str_buffer[BUFFER_SIZE + 1];
	static char	*rst;
	ssize_t		size;
	t_Tuple		rtn;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	size = 0;
	while (1)
	{
		if (!len_to_nl_gnl(rst))
		{
			size = read(fd, str_buffer, BUFFER_SIZE);
			if (size <= 0)
				return (size_handler(size, &rst, &rtn));
			str_buffer[size] = '\0';
			rst = ft_strjoin_gnl(rst, str_buffer);
			if (!rst)
				return (NULL);
			if (!size && rst)
				return (rtn.line = ft_strdup_gnl(rst), free(rst), rtn.line);
		}
		else
			return (rtn = dvd(rst), free(rst), rst = rtn.remain, rtn.line);
	}
}

char	*ft_strjoin_gnl(char *rest, char *str_buffer)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;
	size_t	total;

	if (!rest)
	{
		if (str_buffer)
			return (new_str = ft_strdup_gnl(str_buffer), new_str);
		return (NULL);
	}
	len1 = ft_strlen(rest);
	len2 = ft_strlen(str_buffer);
	total = len1 + len2;
	if (!total)
		return (NULL);
	new_str = malloc(total + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy_gnl(new_str, rest, len1);
	ft_memcpy_gnl((new_str + len1), str_buffer, len2);
	new_str[total] = '\0';
	free(rest);
	return (new_str);
}

t_Tuple	dvd(char *s)
{
	size_t	nl_pos;
	size_t	len;
	t_Tuple	to_return ;

	nl_pos = len_to_nl_gnl(s);
	len = ft_strlen(s);
	to_return.line = NULL;
	to_return.remain = NULL;
	if (nl_pos)
	{
		to_return.line = ft_substr_gnl(s, 0, nl_pos);
		if (!(len == nl_pos))
			to_return.remain = ft_substr_gnl(s, nl_pos, len - nl_pos);
	}
	else
		to_return.remain = ft_strdup_gnl(s);
	return (to_return);
}
