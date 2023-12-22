/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:24:01 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/03 09:06:32 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_error(t_fdf_env *data, char *message)
{
	if ((message == NULL || *message == '\0'))
	{
		ft_putendl_fd(RSTTXT BLDTXT "\t*** Program exiting ***", 2);
		return (KO);
	}
	ft_putendl_fd(message, 2);
	if (data != NULL)
		data->error_flag = true;
	return (KO);
}
