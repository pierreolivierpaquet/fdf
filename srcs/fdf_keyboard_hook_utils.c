/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard_hook_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:07:04 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/05 11:25:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_hook_transposing(mlx_key_data_t keydata, t_fdf_env *data)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		data->y_transpos -= 1;
		data->x_transpos -= 1;
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		data->y_transpos += 1;
		data->x_transpos += 1;
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		data->x_transpos += 1;
		data->y_transpos -= 1.5;
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		data->x_transpos -= 1;
		data->y_transpos += 1.5;
	}
	ft_memset(data->img->pixels, 0, \
	(data->img->height * data->img->width * sizeof(int)));
	fdf_put_lines(data);
	return ;
}

void	fdf_hook_scaling(mlx_key_data_t keydata, t_fdf_env *data)
{
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		if (data->scale < 100)
		{
			data->scale *= 1.05;
			data->y_transpos /= 1.05;
			data->x_transpos /= 1.05;
		}
	}
	else if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
	{
		if (data->scale > 2)
		{
			data->scale /= 1.05;
			data->y_transpos *= 1.05;
			data->x_transpos *= 1.05;
		}
	}
	ft_memset(data->img->pixels, 0, \
	(data->img->height * data->img->width * sizeof(int)));
	fdf_put_lines(data);
	return ;
}

void	fdf_hook_exit(t_fdf_env *data)
{
	ft_memset(data->img->pixels, 0, \
	(data->img->height * data->img->width * sizeof(int)));
	mlx_close_window(data->screen);
	return ;
}

void	fdf_hook_isometric_variation(mlx_key_data_t keydata, t_fdf_env *data)
{
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
	{
		if (data->view_angle > 0.5)
		{
			data->view_angle -= 0.01;
			data->scale /= 1.005;
		}
	}
	else if (keydata.key == MLX_KEY_K && keydata.action == MLX_REPEAT)
	{
		if (data->view_angle < 1)
		{
			data->view_angle += 0.01;
			data->scale *= 1.005;
		}
	}
	ft_memset(data->img->pixels, 0, \
	(data->img->height * data->img->width * sizeof(int)));
	fdf_put_lines(data);
	return ;
}

void	fdf_hook_amplitude(mlx_key_data_t keydata, t_fdf_env *data)
{
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_REPEAT)
	{
		if (data->z_transpos < 3)
			data->z_transpos += 0.05;
	}
	else if (keydata.key == MLX_KEY_U && keydata.action == MLX_REPEAT)
	{
		if (data->z_transpos > -3)
			data->z_transpos -= 0.05;
	}
	ft_memset(data->img->pixels, 0, \
	(data->img->height * data->img->width * sizeof(int)));
	fdf_put_lines(data);
	return ;
}
