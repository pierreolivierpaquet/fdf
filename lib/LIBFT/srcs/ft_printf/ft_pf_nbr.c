/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:49:41 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:31:45 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pf_putnbr(int c, int *len)
{
	long int	n;

	if (*len == -1)
		return ;
	n = (long int)c;
	if (n < 0)
	{
		ft_pf_putchar('-', len);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_pf_putnbr((n / 10), len);
		ft_pf_putnbr((n % 10), len);
	}
	else
	{
		n += 48;
		ft_pf_putchar((n), len);
	}
	return ;
}

void	ft_pf_putunbr(unsigned int c, int *len)
{
	long unsigned int	n;

	if (*len == -1)
		return ;
	n = (long unsigned int)c;
	if (n < 0)
	{
		ft_pf_putchar('-', len);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_pf_putunbr((n / 10), len);
		ft_pf_putunbr((n % 10), len);
	}
	else
	{
		n += 48;
		ft_pf_putchar(n, len);
	}
	return ;
}
