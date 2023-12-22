/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:04:35 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/05 14:57:18 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_coordinate_count(t_fdf_env *data, char *row)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (row[i] == ' ' || (row[i] >= 9 && row[i] <= 13))
		i++;
	while (row[i] != '\0' && row[i] != '\n')
	{
		count++;
		while ((row[i] != '\0' && row[i] != '\n') && row[i] != ' ')
			i++;
		while (row[i] == ' ' || (row[i] >= 9 && row[i] <= 13))
			i++;
	}
	if (data->map_width == DEFAULT && count != data->map_width)
		data->map_width = count;
	else if (count != data->map_width)
	{
		data->error_flag = true;
		return (fdf_error(data, RSTTXT BLDTXT "\t*** Inconsistent map \
width and/or empty newlines the end. ***"));
	}
	return (count);
}

int	fdf_valid_alphanum(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F') || c == 'x' || c == ',')
		return (1);
	return (0);
}

int	fdf_valid_coordinates(t_fdf_env *data, char *row)
{
	int	i;

	i = 0;
	while (row[i] != '\0' && row[i] != '\n')
	{
		if (fdf_valid_alphanum(row[i]) == false
			&& row[i] != '-' && row[i] != ' ')
		{
			data->error_flag = true;
			data->map_height = -1;
			fdf_error(data, RSTTXT BLDTXT "\t*** Invalid coordinate within \
the map. ***");
			return (KO);
		}
		i++;
	}
	return (OK);
}

int	fdf_valid_rows(t_fdf_env *data, char **av)
{
	int		fd;
	char	*line;
	bool	is_line;

	is_line = true;
	fd = open(av[1], O_RDONLY);
	if (fd < OK)
		return (fdf_error(data, RSTTXT BLDTXT"\t*** Opening the map file ***"));
	while (is_line == true)
	{
		line = get_next_line(fd);
		if (line == NULL || fdf_valid_coordinates(data, line) == KO
			|| fdf_coordinate_count(data, line) <= 0)
			is_line = false;
		else
			if (fdf_coordinate_count(data, line) > 0)
				data->map_height++;
		free(line);
		line = NULL;
	}
	fd = close(fd);
	if (data->map_height <= DEFAULT || data->error_flag == true)
		return (false);
	fdf_map_coord_init(data);
	return (true);
}
