/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:11:26 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:35:21 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p_last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p_last = ft_lstlast(*lst);
	(*p_last).next = new;
	return ;
}
