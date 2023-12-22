/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:12:34 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:34:49 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (!s1 || !s2)
		return (0);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((p1[i] == p2[i]) && (p1[i] != '\0' || p2[i] != '\0'))
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return (p1[i] - p2[i]);
}
