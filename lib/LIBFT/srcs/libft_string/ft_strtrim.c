/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:33:10 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/04 12:18:17 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_vali(char const c, char const	*set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trimd;
	size_t		i1;
	size_t		i2;
	size_t		i;

	if (!s1 || !set)
		return (NULL);
	i1 = 0;
	while (s1[i1] != '\0' && char_vali(s1[i1], set) == 1)
		i1++;
	i2 = ft_strlen(s1);
	while (i2 > i1 && char_vali(s1[i2 - 1], set) == 1)
		i2--;
	trimd = (char *)malloc((i2 - i1 + 1) * sizeof(*s1));
	if (trimd == NULL)
		return (NULL);
	i = 0;
	while (i1 < i2)
		trimd[i++] = s1[i1++];
	trimd[i] = 0;
	return (trimd);
}
