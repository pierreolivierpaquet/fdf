/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:34:02 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:34:46 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	buf = (char *)malloc((len + 1) * sizeof(*buf));
	if (buf == NULL)
		return (NULL);
	while (i < len)
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[len] = '\0';
	return (buf);
}
