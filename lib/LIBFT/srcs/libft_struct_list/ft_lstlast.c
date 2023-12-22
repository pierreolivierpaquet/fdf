/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:11:07 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:35:36 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p_lst;

	if (!lst)
		return (NULL);
	p_lst = lst;
	while ((*p_lst).next != NULL)
		p_lst = (*p_lst).next;
	return (p_lst);
}
