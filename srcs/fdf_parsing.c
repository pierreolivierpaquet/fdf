/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:18:06 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/05 14:06:26 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_row_to_tab(t_fdf_env *data, char *row)
{
	char	**tab;
	int		i;

	tab = ft_split(row, ' ');
	if (tab == NULL)
		return (KO);
	i = 0;
	while (i < data->map_width)
	{
		data->map_coord[data->current_row][i] = ft_atoi(tab[i]);
		i++;
	}
	data->current_row++;
	tab = fdf_free_tab(tab);
	return (OK);
}

int	fdf_parse_row(t_fdf_env *data, char *row)
{
	int	coord_count;
	int	*map;

	coord_count = 0;
	if (row == NULL)
		return (KO);
	coord_count = fdf_coordinate_count(data, row);
	if ((coord_count == KO && data->current_row < data->map_height))
		return (OK);
	if (coord_count != data->map_width)
	{
		data->map_height = 0;
		return (KO);
	}
	map = malloc(sizeof(*map) * data->map_width);
	if (map == NULL)
		return (KO);
	data->map_coord[data->current_row] = map;
	return (fdf_row_to_tab(data, row));
}

int	fdf_map_coord_init(t_fdf_env *data)
{
	int	**map;
	int	i;

	i = 0;
	map = malloc((sizeof(*map) * data->map_height));
	if (map == NULL)
		return (KO);
	while (i < data->map_height)
		map[i++] = NULL;
	data->map_coord = map;
	return (OK);
}

void	fdf_map_to_row(t_fdf_env *data, bool check, int fd)
{
	char	*line;

	if (data == NULL || check == false || fd < 3)
		return ;
	line = NULL;
	while (check == true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			check = false;
		else
		{
			if (fdf_parse_row(data, line) == KO)
				check = false;
		}
		free(line);
		line = NULL;
	}
	return ;
}

int	fdf_parse_map(t_fdf_env *data, char **av)
{
	int		map;
	bool	is_row;

	is_row = fdf_valid_rows(data, av);
	if (is_row == false)
		return (KO);
	map = open(av[1], O_RDONLY);
	if (map < OK)
		return (fdf_error(data, "\t*Opening the map file."));
	fdf_map_to_row(data, is_row, map);
	map = close(map);
	if (data->map_height <= 0)
		return (KO);
	data->map_dim = (data->map_width) * (data->map_height);
	fdf_matrix_init(data);
	return (OK);
}
