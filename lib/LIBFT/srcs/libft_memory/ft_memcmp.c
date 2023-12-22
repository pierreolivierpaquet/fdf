/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:13:26 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:33:39 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;
	size_t			i;

	if (!s1 || !s2)
		return (0);
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (p_s1[i] == p_s2[i])
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return (p_s1[i] - p_s2[i]);
}
