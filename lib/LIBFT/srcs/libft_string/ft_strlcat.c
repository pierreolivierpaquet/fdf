/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:46 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:34:36 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idst;
	size_t	isrc;
	int		i;

	if (!dst || !src)
		return (0);
	idst = ft_strlen(dst);
	isrc = ft_strlen(src);
	if (dstsize <= idst)
		return (dstsize + isrc);
	i = 0;
	while (src[i] != '\0' && (idst + 1 < dstsize))
		dst[idst++] = src[i++];
	dst[idst] = '\0';
	return (idst + ft_strlen(&src[i]));
}
