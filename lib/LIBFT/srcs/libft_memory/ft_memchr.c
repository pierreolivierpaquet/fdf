/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:12:57 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:33:35 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s;
	unsigned char	c2;

	if (!s)
		return (NULL);
	i = 0;
	ptr_s = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (ptr_s[i] == c2)
		{
			return (&ptr_s[i]);
		}
		i++;
	}
	return (NULL);
}
