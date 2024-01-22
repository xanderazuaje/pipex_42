/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 02:23:36 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/07 20:55:31 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	skip_spaces(size_t *i, const char *str)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
	{
		*i += 1;
	}
}

static void	check_sign(size_t *i, const char *str, int *sign)
{
	if ((str[*i] == '-' || str[*i] == '+') && ft_isdigit(str[*i + 1]))
	{
		*sign = (str[*i] - 44) * -1;
		*i += 1;
	}
}

int	ft_atoi(const char *str)
{
	int		res;
	int		sign;
	size_t	i;

	res = 0;
	sign = 1;
	i = 0;
	skip_spaces(&i, str);
	check_sign(&i, str, &sign);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
			{
				res = (res * 10) + (str[i] - '0');
				i++;
			}
			break ;
		}
		break ;
	}
	return (res * sign);
}

int	ft_atoi_pos(const char *str, size_t *pos)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	skip_spaces(pos, str);
	check_sign(pos, str, &sign);
	while (str[*pos])
	{
		if (ft_isdigit(str[*pos]))
		{
			while (ft_isdigit(str[*pos]))
			{
				res = (res * 10) + (str[*pos] - '0');
				*pos += 1;
			}
			break ;
		}
		break ;
	}
	return (res * sign);
}
