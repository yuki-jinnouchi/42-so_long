/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:34:19 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 16:20:34 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_put_walls(t_vars *vars)
{
	int			i;
	t_sprite	wall;
	t_map		*map;

	map = vars->map;
	wall.reference = so_long_image_wrap(vars->mlx, "textures/wood.xpm");
	i = 0;
	while (i < (map->height * map->width))
	{
		if (map->structure[i / map->width][i % map->width] == '1')
			so_long_put_sprite_wrap(vars, wall, i);
		i++;
	}
	mlx_destroy_image(vars->mlx, wall.reference);
}

void	so_long_put_fields_all(t_vars *vars)
{
	int			i;
	t_sprite	nazo;
	t_sprite	hara;
	t_map		*map;

	map = vars->map;
	nazo.reference = so_long_image_wrap(vars->mlx, "textures/nazo.xpm");
	hara.reference = so_long_image_wrap(vars->mlx, "textures/hara.xpm");
	i = 0;
	while (i < (map->height * map->width))
	{
		if (map->structure[i / map->width][i % map->width] != '1')
		{
			if (i % 5 < 3)
				so_long_put_sprite_wrap(vars, nazo, i);
			if (i % 5 >= 3)
				so_long_put_sprite_wrap(vars, hara, i);
		}
		i++;
	}
	mlx_destroy_image(vars->mlx, nazo.reference);
	mlx_destroy_image(vars->mlx, hara.reference);
}

void	so_long_put_pals(t_vars *vars)
{
	int			i;
	t_sprite	pal_00;
	t_sprite	pal_01;
	t_map		*map;

	map = vars->map;
	pal_00.reference = so_long_image_wrap(vars->mlx, "textures/m00.xpm");
	pal_01.reference = so_long_image_wrap(vars->mlx, "textures/m01.xpm");
	i = 0;
	while (i < (map->height) * (map->width))
	{
		if (map->structure[i / map->width][i % map->width] == 'C')
		{
			if ((vars->player->point->x + vars->player->point->y + i) % 2 == 0)
				so_long_put_sprite_wrap(vars, pal_00, i);
			else
				so_long_put_sprite_wrap(vars, pal_01, i);
		}
		i++;
	}
	mlx_destroy_image(vars->mlx, pal_00.reference);
	mlx_destroy_image(vars->mlx, pal_01.reference);
}

void	so_long_put_exit(t_vars *vars)
{
	int			i;
	t_sprite	o_00;
	t_sprite	o_01;
	t_map		*map;

	if (vars->flag == 0)
		return ;
	map = vars->map;
	o_00.reference = so_long_image_wrap(vars->mlx, "textures/o00.xpm");
	o_01.reference = so_long_image_wrap(vars->mlx, "textures/o01.xpm");
	i = 0;
	while (i < (map->height * map->width))
	{
		if (map->structure[i / map->width][i % map->width] == 'E')
		{
			if ((vars->player->point->x + vars->player->point->y + i) % 2 == 0)
				so_long_put_sprite_wrap(vars, o_00, i);
			else
				so_long_put_sprite_wrap(vars, o_01, i);
		}
		i++;
	}
	mlx_destroy_image(vars->mlx, o_00.reference);
	mlx_destroy_image(vars->mlx, o_01.reference);
}
