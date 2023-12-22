/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:39:45 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/04 15:10:13 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_keypress(mlx_key_data_t keydata, void *param)
{
	t_fdf_env	*data;

	data = (t_fdf_env *)param;
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN
		|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		return (fdf_hook_transposing(keydata, data));
	else if (keydata.key == MLX_KEY_P || keydata.key == MLX_KEY_O)
		return (fdf_hook_scaling(keydata, data));
	else if (keydata.key == MLX_KEY_ESCAPE)
		return (fdf_hook_exit(data));
	else if (keydata.key == MLX_KEY_K || keydata.key == MLX_KEY_L)
		return (fdf_hook_isometric_variation(keydata, data));
	else if (keydata.key == MLX_KEY_I || keydata.key == MLX_KEY_U)
		return (fdf_hook_amplitude(keydata, data));
	return ;
}
