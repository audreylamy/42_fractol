/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:31:37 by alamy             #+#    #+#             */
/*   Updated: 2017/11/20 07:23:16 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newliste;

	newliste = ft_lstnew(lst->content, lst->content_size);
	if (!newliste)
		return (NULL);
	newliste = f(lst);
	if (lst->next)
	{
		newliste->next = ft_lstmap(lst->next, f);
		if (newliste->next == NULL)
		{
			free(newliste);
			return (NULL);
		}
	}
	return (newliste);
}
