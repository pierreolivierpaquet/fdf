/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:48:46 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/04 12:17:25 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Write the character, and increment by 1 the lenght
//	by dereferencing the pointer.
void	ft_pf_putchar(int c, int *len)
{
	if (*len == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*len = -1;
	else if (*len >= 0)
		*len += 1;
}

//	Print the string using ft_pf_putchar, and increment
//	by 1 the total lenght by dereferencing the pointer.
void	ft_pf_putstr(char *str, int *len)
{
	int	i;

	if (*len == -1)
		return ;
	if (str == NULL)
	{
		ft_pf_putstr("(null)", len);
		return ;
	}
	i = 0;
	while (str[i])
		ft_pf_putchar(str[i++], len);
	return ;
}
