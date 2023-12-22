/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:32:32 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:35:17 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = (char *)ft_calloc(1, sizeof(char));
		if (!sub)
			return (NULL);
		return (sub);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(*sub));
	if (!sub)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}
