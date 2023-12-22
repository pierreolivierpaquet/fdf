/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:13:58 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:34:53 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i1;
	size_t	i2;
	size_t	needlen;

	if (!haystack || !needle)
		return (NULL);
	needlen = ft_strlen(needle);
	if (needlen == 0)
		return ((char *)haystack);
	i1 = 0;
	while (haystack[i1] != '\0' && i1 < len)
	{
		i2 = 0;
		while ((haystack[i1 + i2] == needle[i2]) && (i1 + i2) < len)
		{
			if (i2 == (needlen - 1))
				return ((char *)&haystack[i1]);
			i2++;
		}
		i1++;
	}
	return (NULL);
}
