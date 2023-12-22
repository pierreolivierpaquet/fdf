/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:33:41 by ppaquet           #+#    #+#             */
/*   Updated: 2023/07/04 13:56:03 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc > 2)
		return (fdf_error(NULL, BLDTXT REDTXT"[ERROR] Too many arguments.\n"\
		RSTTXT "Please make sure to only specify one map."));
	if (argc < 2)
		return (fdf_error(NULL, BLDTXT REDTXT"[ERROR] Missing (or invalid) \
argument." RSTTXT "\nPlease specify a valid map."));
	if (fdf_valid_file(argv[1]) == KO
		|| fdf_valid_extension(argv[1]) == KO)
		return (fdf_error(NULL, ""));
	fdf(argv);
	return (0);
}
