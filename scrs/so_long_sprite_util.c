/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_sprite_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:34:19 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 16:20:26 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*so_long_image_wrap(void *xvar, char *file)
{
	void	*ptr;
	int		size;

	size = BASE_SIZE;
	ptr = mlx_xpm_file_to_image(xvar, file, &size, &size);
	return (ptr);
}

void	so_long_put_sprite_wrap(t_vars *vars, t_sprite icon, int i)
{
	t_map	*map;

	map = vars->map;
	mlx_put_image_to_window(vars->mlx, vars->win, icon.reference, \
		BASE_SIZE * (i % map->width), BASE_SIZE * (i / map->width));
}
