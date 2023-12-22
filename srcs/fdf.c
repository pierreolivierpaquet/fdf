/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:31:34 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/05 14:07:50 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_env	*fdf_env_new(void)
{
	t_fdf_env	*env_init;

	env_init = NULL;
	env_init = malloc(sizeof(*env_init));
	if (env_init == NULL)
		return (NULL);
	env_init->map_width = DEFAULT;
	env_init->map_height = DEFAULT;
	env_init->map_dim = DEFAULT;
	env_init->x_transpos = DEFAULT;
	env_init->y_transpos = DEFAULT;
	env_init->z_transpos = 1;
	env_init->map_coord = NULL;
	env_init->matrix = NULL;
	env_init->gnd_lvl = DEFAULT;
	env_init->color[0] = WHITE;
	env_init->color[1] = GREEN;
	env_init->color[2] = PURPLE;
	env_init->scale = 20;
	env_init->view_angle = 1;
	env_init->current_row = DEFAULT;
	env_init->screen = NULL;
	env_init->img = NULL;
	env_init->error_flag = false;
	return (env_init);
}

t_fdf_env	*fdf_init(char **av)
{
	t_fdf_env	*fdf;

	if (av == NULL || av[1] == NULL)
		return (NULL);
	fdf = NULL;
	fdf = fdf_env_new();
	if (fdf == NULL)
		return (NULL);
	if (fdf_parse_map(fdf, av) == KO
		|| (fdf->map_height <= 0 && fdf->current_row != DEFAULT))
	{
		fdf_error(NULL, BLDTXT REDTXT "[ERROR] Inconsistent map.");
		return (fdf_free_env(&fdf));
	}
	return (fdf);
}

int	fdf_valid_extension(char *ext)
{
	int	i;

	i = (int)ft_strlen(ext);
	if (ft_strncmp(&ext[i - 4], MAP_EXT, 4) == OK)
		return (OK);
	return (fdf_error(NULL, REDTXT BLDTXT "[ERROR] Invalid map extension."));
}

int	fdf_valid_file(char *av)
{
	int		valid_file;
	char	check[1];

	check[0] = '\0';
	valid_file = open(av, O_RDONLY);
	if (valid_file < 0)
		return (fdf_error(NULL, BLDTXT REDTXT "[ERROR] The specified file \
does not exists, or there is an error in the file name.\n"\
RSTTXT "Please check the path and/or name provided, then try again."));
	read(valid_file, check, 1);
	if (check[0] == '\0' || check[0] == '\n'
		|| (fdf_valid_alphanum(check[0]) != 1))
	{
		if (check[0] != '-' && check[0] != ' ')
			return (fdf_error(NULL, BLDTXT REDTXT "[ERROR] Please make sure \
that the specified map file is not empty,\nOR that it does not contain '\\n', \
'\\0', or non-numeric as first character of the first row."));
	}
	else
		check[0] = '\0';
	return (OK);
}

int	fdf(char **map)
{
	t_fdf_env	*fdf;

	fdf = fdf_init(map);
	if (fdf == NULL)
		return (fdf_error(fdf, ""));
	if (fdf->error_flag == false)
		fdf_graphic_init(fdf);
	fdf_menu(fdf);
	fdf_put_lines(fdf);
	mlx_key_hook(fdf->screen, &fdf_keypress, fdf);
	mlx_loop(fdf->screen);
	mlx_delete_image(fdf->screen, fdf->img);
	mlx_terminate(fdf->screen);
	fdf = fdf_free_env(&fdf);
	return (OK);
}
