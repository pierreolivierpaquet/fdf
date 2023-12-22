/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:33:45 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:33:18 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	n_buf;
	char		*a;
	int			len;

	n_buf = (long int)n;
	len = nbr_len(n_buf);
	a = (char *)malloc((len + 1) * sizeof(*a));
	if (a == NULL)
		return (NULL);
	a[len] = '\0';
	if (n_buf == 0)
		a[0] = '0';
	if (n < 0)
	{
		a[0] = '-';
		n_buf = (n_buf * -1);
	}
	while (n_buf != 0)
	{
		a[--len] = (n_buf % 10) + '0';
		n_buf = (n_buf / 10);
	}
	return (a);
}
