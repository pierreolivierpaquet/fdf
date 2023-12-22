/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:12:13 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:34:56 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	ifin;

	if (!s)
		return (NULL);
	ifin = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[ifin]);
	while (ifin >= 0)
	{
		if (s[ifin] == (char)c)
		{
			return ((char *)&s[ifin]);
		}
		ifin--;
	}
	return (NULL);
}
