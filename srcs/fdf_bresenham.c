/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:08:17 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/05 15:10:42 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_absolute_maximum(float x, float y, float *absolute_maximum)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
		*absolute_maximum = x;
	else
		*absolute_maximum = y;
	return ;
}

void	fdf_bresenham(t_coord a, t_coord b, t_fdf_env *data)
{
	float	x_diff;
	float	y_diff;
	float	abs_max;

	fdf_apply_parameters(&a, &b, data);
	x_diff = b.x - a.x;
	y_diff = b.y - a.y;
	fdf_absolute_maximum(x_diff, y_diff, &abs_max);
	x_diff /= abs_max;
	y_diff /= abs_max;
	while ((int)(a.x - b.x) != 0 || (int)(a.y - b.y) != 0)
	{
		if ((a.x >= 0 && a.x < data->screen->width)
			&& (a.y >= 0 && a.y < data->screen->height))
		{
			if ((a.z != data->gnd_lvl || b.z != data->gnd_lvl) && (a.z != b.z))
				mlx_put_pixel(data->img, a.x, a.y, data->color[2]);
			else if ((a.z != data->gnd_lvl && b.z != data->gnd_lvl))
				mlx_put_pixel(data->img, a.x, a.y, data->color[1]);
			else
				mlx_put_pixel(data->img, a.x, a.y, data->color[0]);
		}
		a.x += x_diff;
		a.y += y_diff;
	}
}

void	fdf_put_lines(t_fdf_env *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (x < data->map_width - 1)
				fdf_bresenham(data->matrix[y][x], data->matrix[y][x + 1], data);
			if (y < data->map_height - 1)
				fdf_bresenham(data->matrix[y][x], data->matrix[y + 1][x], data);
			x++;
		}
		y++;
	}
}
