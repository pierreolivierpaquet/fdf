/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:34:31 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:31:41 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Print the hexadecimal value of the unsigned int 'ptr', 
//	using the ft_pf_putchar function, increment the total lenght
//	by 1 dereferencing the pointer., checking if the the format is
//	'x' for lowercase, and 'X' for uppercase output.
void	ft_pf_puthex(unsigned int ptr, int *len, char x_min_or_maj)
{
	if (ptr >= 16)
	{
		ft_pf_puthex((ptr / 16), len, x_min_or_maj);
		ft_pf_puthex((ptr % 16), len, x_min_or_maj);
	}
	else if (ptr < 10)
	{
		ptr += '0';
		ft_pf_putchar(ptr, len);
	}
	else if (ptr >= 10)
	{
		if (x_min_or_maj == 'x')
		{
			ptr = (ptr - 10) + 'a';
			ft_pf_putchar(ptr, len);
		}
		else if (x_min_or_maj == 'X')
		{
			ptr = (ptr - 10) + 'A';
			ft_pf_putchar(ptr, len);
		}
	}
	return ;
}

//	Print the pointer hexadecimal value of the unsigned long int
//	'ptr', using the ft_pf_putchar function, increment the total
//	lenght by 1 dereferencing the pointer.
void	ft_pf_putphex(unsigned long int ptr, int *len)
{
	if (ptr >= 16)
	{
		ft_pf_putphex((ptr / 16), len);
		ft_pf_putphex((ptr % 16), len);
	}
	else if (ptr < 10)
	{
		ptr += '0';
		ft_pf_putchar(ptr, len);
	}
	else if (ptr >= 10)
	{
		ptr = (ptr - 10) + 'a';
		ft_pf_putchar(ptr, len);
	}
	return ;
}

//	Print the prefix of a pointer adress, then the adress
//	using the ft_pf_putphex function, increment the total
//	lenght by 1 dereferencing the pointer.
void	ft_pf_putptr(unsigned long int ptr, int *len)
{
	ft_pf_putstr("0x", len);
	if (ptr == 0)
		ft_pf_putchar('0', len);
	else
		ft_pf_putphex(ptr, len);
	return ;
}
