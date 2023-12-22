/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:30:27 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/05 14:42:47 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_graphic_init(t_fdf_env *data)
{
	if (data == NULL || data->screen != NULL)
		return (KO);
	data->screen = mlx_init(WDW_WIDTH, WDW_HEIGHT, "FDF - ppaquet", true);
	if (data->screen == NULL)
		return (fdf_error(data, "[ERROR] Initializing screen."));
	data->img = mlx_new_image(data->screen, WDW_WIDTH, WDW_HEIGHT);
	if (data->img == NULL)
		return (fdf_error(data, "[ERROR] Initializing image."));
	if (data->screen != NULL && data->img != NULL)
	{
		if (mlx_image_to_window(data->screen, data->img, 0, 0) == KO)
			return (fdf_error(data, "[ERROR] Inserting image to screen."));
	}
	return (OK);
}

void	fdf_menu(t_fdf_env *data)
{
	int	x;
	int	y;
	int	i;
	int	l;

	if (data == NULL || data->screen == NULL)
		return ;
	x = WDW_WIDTH / 2 + 400;
	y = WDW_HEIGHT / 2 + 250;
	i = 24;
	l = 0;
	mlx_put_string(data->screen, "___________________________[INSTRUCTIONS]", \
x, y + (l++ *i));
	l++;
	mlx_put_string(data->screen, "EXIT FDF.........press ESC", x, y + (l++ *i));
	l++;
	mlx_put_string(data->screen, "MOVE.............press LEFT/RIGHT/UP/DOWN", \
x, y + (l++ *i));
	mlx_put_string(data->screen, "SCALE............press O/P", x, y + (l++ *i));
	mlx_put_string(data->screen, "ISOM. POV...long press K/L", x, y + (l++ *i));
	mlx_put_string(data->screen, "ALTITUDE....long press U/I", x, y + (l++ *i));
	mlx_put_string(data->screen, "__________________________________ppaquet", \
x, y + (l++ *i));
}
