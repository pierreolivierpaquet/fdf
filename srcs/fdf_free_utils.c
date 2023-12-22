/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:59:03 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/05 14:08:16 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	**fdf_free_matrix(t_fdf_env **data)
{
	int	x;
	int	y;

	y = 0;
	if ((*data) == NULL || (*data)->matrix == NULL
		|| ((*data)->error_flag == true && (*data)->map_height == -1))
		return (NULL);
	while (y < (*data)->map_height && (*data)->matrix[y] != NULL)
	{
		x = 0;
		while (x < (*data)->map_width)
		{
			(*data)->matrix[y][x].x = DEFAULT;
			(*data)->matrix[y][x].y = DEFAULT;
			(*data)->matrix[y][x].z = DEFAULT;
			(*data)->matrix[y][x].end = false;
			x++;
		}
		free((*data)->matrix[y]);
		(*data)->matrix[y] = NULL;
		y++;
	}
	free((*data)->matrix);
	(*data)->matrix = NULL;
	return ((*data)->matrix);
}

char	**fdf_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (NULL);
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

int	**fdf_free_map_coord(t_fdf_env **data)
{
	int	i;
	int	j;

	if ((*data)->map_coord == NULL || data == NULL)
		return (NULL);
	i = 0;
	while (i < (*data)->current_row)
	{
		j = 0;
		while (j < (*data)->map_width)
		{
			(*data)->map_coord[i][j] = 0;
			j++;
		}
		free((*data)->map_coord[i]);
		(*data)->map_coord[i] = NULL;
		i++;
	}
	free((*data)->map_coord);
	(*data)->map_coord = NULL;
	return (NULL);
}

t_fdf_env	*fdf_free_env(t_fdf_env **data)
{
	(*data)->map_coord = fdf_free_map_coord(data);
	(*data)->matrix = fdf_free_matrix(data);
	(*data)->map_width = DEFAULT;
	(*data)->map_height = DEFAULT;
	(*data)->map_dim = DEFAULT;
	(*data)->x_transpos = DEFAULT;
	(*data)->y_transpos = DEFAULT;
	(*data)->z_transpos = DEFAULT;
	(*data)->gnd_lvl = DEFAULT;
	(*data)->color[0] = DEFAULT;
	(*data)->color[1] = DEFAULT;
	(*data)->color[2] = DEFAULT;
	(*data)->current_row = DEFAULT;
	(*data)->scale = DEFAULT;
	(*data)->view_angle = DEFAULT;
	(*data)->screen = NULL;
	(*data)->img = NULL;
	(*data)->error_flag = false;
	free(*data);
	*data = NULL;
	return (*data);
}
