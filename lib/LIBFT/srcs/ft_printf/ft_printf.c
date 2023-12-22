/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:28:24 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:31:48 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Validates which format is referenced with the character
//	that follows '%', then send the argument in the related
//	function.
static void	ft_pf_formatval(const char *str, va_list ap, int *len)
{
	if (str[0] == 'c')
		return (ft_pf_putchar(va_arg(ap, int), len));
	if (str[0] == 'i' || str[0] == 'd' )
		return (ft_pf_putnbr(va_arg(ap, int), len));
	if (str[0] == 's')
		return (ft_pf_putstr(va_arg(ap, char *), len));
	if (str[0] == 'u')
		return (ft_pf_putunbr(va_arg(ap, unsigned int), len));
	if (str[0] == '%')
		return (ft_pf_putchar('%', len));
	if (str[0] == 'p')
		return (ft_pf_putptr(va_arg(ap, unsigned long int), len));
	if (str[0] == 'x' || str[0] == 'X')
		return (ft_pf_puthex(va_arg(ap, unsigned long int), len, str[0]));
	return ;
}

//	formats and prints its arguments, after the first,
//	under control of the format.
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		total_l;

	if (!str)
		return (0);
	va_start(ap, str);
	i = 0;
	total_l = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_pf_formatval(&str[++i], ap, &total_l);
			i++;
		}
		else
			ft_pf_putchar(str[i++], &total_l);
	}
	va_end(ap);
	return (total_l);
}
