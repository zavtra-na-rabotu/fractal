/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:16 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:30 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_delete(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *previous;
	t_list *current;

	previous = NULL;
	current = NULL;
	if (f)
	{
		while (lst)
		{
			if (!(temp = f(lst)))
			{
				if (current)
					ft_lstdel(&current, &ft_delete);
				return (NULL);
			}
			if (previous)
				previous->next = temp;
			else
				current = temp;
			previous = temp;
			lst = lst->next;
		}
	}
	return (current);
}
