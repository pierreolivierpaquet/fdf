/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:23:49 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/05 14:07:18 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

// -----------------------------------< TEXT ATTRIBUTES
# define BLDTXT "\x1b[1m"
# define REDTXT "\x1b[31m"
# define RSTTXT "\x1b[0m"

// -----------------------------------< WINDOW DIMENSIONS
# define WDW_WIDTH 1980
# define WDW_HEIGHT 1080

// -----------------------------------< INITIALIZATION
# define DEFAULT 0

// -----------------------------------< VERIFICATION
# define OK 0
# define KO -1
# define MAP_EXT ".fdf"

// -----------------------------------< LINE COLORS
# define WHITE 0xFFFFFFFF
# define PURPLE 0x8109F2FF
# define GREEN 0x18FF81FF

// ----------------------------------------------------------< STRUCTURES >----

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
	bool	end;
}	t_coord;

/**
 *@param map_width The 'x'value maximum (amount of columns).
 *@param map_height The 'y'value maximum (amount of rows).
 *@param map_coord Arrays of int that holds the x,y,z values from map parsing.
 *@param screen The program window that will popup on the display.
 *@param img The image that will be displayed on the window
*/
typedef struct s_fdf_env
{
	int				map_width;
	int				map_height;
	int				map_dim;
	float			x_transpos;
	float			y_transpos;
	float			z_transpos;
	int				**map_coord;
	double			gnd_lvl;
	double			scale;
	float			view_angle;
	int				current_row;
	unsigned int	color[3];
	t_coord			**matrix;
	mlx_t			*screen;
	mlx_image_t		*img;
	bool			error_flag;
}	t_fdf_env;

// ---------------------------------------------------------< ENVIRONMENT >----

int			fdf(char **map);
t_fdf_env	*fdf_env_new(void);
t_fdf_env	*fdf_init(char **av);

// -------------------------------------------------------------< GRAPHIC >----

void		fdf_menu(t_fdf_env *data);
int			fdf_graphic_init(t_fdf_env *data);

void		fdf_absolute_maximum(float x, float y, float *absolute_maximum);
void		fdf_apply_parameters(t_coord *a, t_coord *b, t_fdf_env *data);

void		fdf_scaling(t_coord *a, t_coord *b, t_fdf_env *data);
void		fdf_transposing(t_coord *a, t_coord *b, t_fdf_env *data);
void		fdf_view_isometric(t_coord *a, t_coord *b, t_fdf_env *data);
void		fdf_bresenham(t_coord a, t_coord b, t_fdf_env *data);
void		fdf_put_lines(t_fdf_env *data);

void		fdf_hook_transposing(mlx_key_data_t keydata, t_fdf_env *data);
void		fdf_hook_scaling(mlx_key_data_t keydata, t_fdf_env *data);
void		fdf_hook_exit(t_fdf_env *data);
void		fdf_hook_isometric_variation(mlx_key_data_t keydata, \
t_fdf_env *data);
void		fdf_hook_amplitude(mlx_key_data_t keydata, t_fdf_env *data);

void		fdf_keypress(mlx_key_data_t key, void *param);

// --------------------------------------------------------------< ERRORS >----

int			fdf_error(t_fdf_env *data, char *message);

// -------------------------------------------------------------< PARSING >----

int			fdf_row_to_tab(t_fdf_env *data, char *row);
int			fdf_parse_row(t_fdf_env *data, char *row);
int			fdf_map_coord_init(t_fdf_env *data);
void		fdf_map_to_row(t_fdf_env *data, bool check, int fd);
int			fdf_parse_map(t_fdf_env *data, char **av);

int			fdf_tab_to_matrix(t_fdf_env *data, int i);
int			fdf_matrix_init(t_fdf_env *data);

// ----------------------------------------------------------< FREE UTILS >----

t_coord		**fdf_free_matrix(t_fdf_env **data);
char		**fdf_free_tab(char **tab);
int			**fdf_free_map_coord(t_fdf_env **data);
t_fdf_env	*fdf_free_env(t_fdf_env **data);

// --------------------------------------------------------------< CHECKS >----

int			fdf_valid_extension(char *ext);
int			fdf_valid_file(char *av);

int			fdf_coordinate_count(t_fdf_env *data, char *row);
int			fdf_valid_alphanum(char c);
int			fdf_valid_coordinates(t_fdf_env *data, char *row);
int			fdf_valid_rows(t_fdf_env *data, char **av);

#endif
