/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:07:25 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:33:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr_s;

	if (!s)
		return ;
	i = 0;
	ptr_s = s;
	if (n == 0)
		return ;
	while (i < n)
		ptr_s[i++] = 0;
}
