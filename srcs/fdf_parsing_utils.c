/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:46:52 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/05 14:09:27 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_tab_to_matrix(t_fdf_env *data, int i)
{
	t_coord	*row_init;
	int		x;

	row_init = malloc(sizeof(*row_init) * data->map_width);
	if (row_init == NULL)
		return (fdf_error(data, "[ERROR] Creating matrix row."));
	data->matrix[i] = row_init;
	x = 0;
	while (x < data->map_width)
	{
		data->matrix[i][x].x = x;
		data->matrix[i][x].y = i;
		data->matrix[i][x].z = data->map_coord[i][x];
		data->matrix[i][x].end = false;
		if ((x == 0 && i == 0) || (data->matrix[i][x].z < data->gnd_lvl
			&& data->gnd_lvl >= 0))
			data->gnd_lvl = data->matrix[i][x].z;
		x++;
	}
	data->matrix[i][x - 1].end = true;
	return (OK);
}

int	fdf_matrix_init(t_fdf_env *data)
{
	t_coord	**matrix_init;
	int		i;

	i = 0;
	if (data == NULL || data->map_coord == NULL || data->map_dim == 0)
		return (KO);
	matrix_init = malloc(sizeof(*matrix_init) * data->map_height);
	if (matrix_init == NULL)
		return (fdf_error(data, "[ERROR] Creating coordinates matrix."));
	while (i < data->map_height)
		matrix_init[i++] = NULL;
	data->matrix = matrix_init;
	i = 0;
	while (i < data->map_height)
	{
		if (fdf_tab_to_matrix(data, i) == KO)
		{
			data->matrix = fdf_free_matrix(&data);
			return (KO);
		}
		i++;
	}
	return (OK);
}
