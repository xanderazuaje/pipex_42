/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:48:58 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/07 21:22:03 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	word_counter(char const *s, char c)
{
	size_t	i;
	size_t	cw;

	i = 0;
	cw = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
			cw++;
		if (s[i] != c && s[i + 1] == '\0')
			cw++;
		i++;
	}
	return (cw);
}

static void	free_fail(t_splitted *splitted)
{
	size_t	i;
	char	**s;

	i = 0;
	s = splitted->string;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	free(splitted);
}

void	start_to_count(const char *s, size_t *i, size_t *end, char c)
{
	while (s[*i] == c)
		*i += 1;
	*end = *i;
	while (s[*i] && s[*i] != c)
		*i += 1;
}

static t_splitted	*initializer(size_t *len, char const *s, char c)
{
	t_splitted	*new;

	*len = word_counter(s, c);
	new = (t_splitted *)malloc(sizeof(t_splitted));
	if (!new)
		return (NULL);
	new->string = (char **)malloc(sizeof(char *) * (*len + 1));
	new->len = *len;
	if (!new->string)
		return (NULL);
	return (new);
}

t_splitted	*ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		end;
	size_t		len;
	t_splitted	*new;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	new = initializer(&len, s, c);
	if (!new)
		return (NULL);
	while (s[i])
	{
		start_to_count(s, &i, &end, c);
		if (i > end)
		{
			new->string[j] = ft_substr(s, end, i - end);
			if (!new->string[j])
				return (free_fail(new), NULL);
			j++;
		}
	}
	return (new->string[j] = NULL, new);
}
