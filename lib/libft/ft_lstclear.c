/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:03:18 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/21 22:58:07 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*prev;

	prev = lst[0];
	current = lst[0];
	if (!prev)
		return ;
	if (prev->next)
	{
		while (prev->next)
		{
			current = prev->next;
			del(prev->content);
			free(prev);
			prev = current;
		}
		del(current->content);
		free(current);
	}
	else
	{
		del(prev->content);
		free(prev);
	}
	*lst = 0;
}
/*

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_print_result(t_list *elem)
{
	write(1, elem->content, strlen(elem->content));
}

static int	nb_free_done;

void	ft_del(void *content)
{
	free(content);
	nb_free_done++;
}

t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
		elem->content = NULL;
	else
		elem->content = content;
	elem->next = NULL;
	return (elem);
}

int	main(void)
{
	t_list	*elem;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;

	str = strdup("lorem");
	str2 = strdup("ipsum");
	str3 = strdup("dolor");
	str4 = strdup("sit");
	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	nb_free_done = 0;
	ft_lstclear(&elem3, &ft_del);
	if (elem)
		ft_print_result(elem);
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem2)
		ft_print_result(elem2);
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem3)
		ft_print_result(elem3);
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem4)
	{
		write(1, "nb_free_done = ", 15);
		nb_free_done += '0';
		write(1, &nb_free_done, 1);
	}
	else
		write(1, "NULL", 4);
	return (0);
}
*/
