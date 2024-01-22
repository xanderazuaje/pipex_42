/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:56:02 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/22 10:45:48 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	delete_all(t_list **first, void *result, void (*del)(void *))
{
	del(result);
	ft_lstclear(first, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*ptr;
	void	*result;

	first = 0;
	ptr = 0;
	result = 0;
	while (lst)
	{
		result = f(lst->content);
		if (!result)
			return (delete_all(&first, result, del), (NULL));
		ptr = ft_lstnew(result);
		if (!ptr)
			return (delete_all(&first, result, del), (NULL));
		ft_lstadd_back(&first, ptr);
		lst = lst->next;
	}
	return (first);
}
