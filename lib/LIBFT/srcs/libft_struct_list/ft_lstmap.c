/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:13:21 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/04 12:18:33 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_tl;
	t_list	*head;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst != NULL)
	{
		temp = (f)((*lst).content);
		new_tl = ft_lstnew(temp);
		if (new_tl == NULL)
		{
			ft_lstclear(&head, del);
			free (temp);
			return (NULL);
		}
		ft_lstadd_back(&head, new_tl);
		lst = (*lst).next;
	}
	return (head);
}
