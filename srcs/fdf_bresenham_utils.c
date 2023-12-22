/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:35:14 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/05 15:10:39 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_scaling(t_coord *a, t_coord *b, t_fdf_env *data)
{
	(*a).x *= data->scale;
	(*a).y *= data->scale;
	(*a).z *= data->scale;
	(*b).x *= data->scale;
	(*b).y *= data->scale;
	(*b).z *= data->scale;
	return ;
}

void	fdf_transposing(t_coord *a, t_coord *b, t_fdf_env *data)
{
	(*a).x += data->x_transpos;
	(*a).y += data->y_transpos;
	(*b).x += data->x_transpos;
	(*b).y += data->y_transpos;
	return ;
}

void	fdf_view_isometric(t_coord *a, t_coord *b, t_fdf_env *data)
{
	if (data == NULL)
		return ;
	if (a != NULL)
	{
		(*a).x = ((*a).x - (*a).y) * cos(data->view_angle) + 200;
		(*a).y = ((*a).x + (*a).y) * sin(data->view_angle) - (*a).z + 100;
	}
	if (b != NULL)
	{
		(*b).x = ((*b).x - (*b).y) * cos(data->view_angle) + 200;
		(*b).y = ((*b).x + (*b).y) * sin(data->view_angle) - (*b).z + 100;
	}
	return ;
}

void	fdf_leveling(t_coord *a, t_coord *b, t_fdf_env *data)
{
	if ((*a).z != data->gnd_lvl)
		(*a).z *= data->z_transpos;
	if ((*b).z != data->gnd_lvl)
		(*b).z *= data->z_transpos;
}

void	fdf_apply_parameters(t_coord *a, t_coord *b, t_fdf_env *data)
{
	fdf_transposing(a, b, data);
	fdf_leveling(a, b, data);
	fdf_scaling(a, b, data);
	fdf_view_isometric(a, b, data);
	return ;
}
