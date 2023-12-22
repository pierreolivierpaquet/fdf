/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:46 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:35:47 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p_lst;
	int		n;

	if (!lst)
		return (0);
	n = 0;
	p_lst = lst;
	while (p_lst != NULL)
	{
		n++;
		p_lst = (*p_lst).next;
	}
	return (n);
}
