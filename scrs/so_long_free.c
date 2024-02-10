/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:03:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 14:24:34 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_free_map_structure(t_map *map)
{
	int	i;

	if (map)
	{
		if (map->structure != NULL)
		{
			i = 0;
			while (i < map->height)
			{
				free(map->structure[i]);
				map->structure[i] = NULL;
				i++;
			}
			free(map->structure);
			map->structure = NULL;
		}
	}
	return ;
}

void	so_long_free_map(t_map *map)
{
	if (map)
	{
		if (map->structure)
			so_long_free_map_structure(map);
		free(map);
		map = NULL;
	}
	return ;
}

void	so_long_free_vars(t_vars *vars)
{
	if (vars)
	{
		if (vars->map)
			so_long_free_map(vars->map);
		if (vars->player)
		{
			if (vars->player->sprite)
				free(vars->player->sprite);
			if (vars->player->point)
				free(vars->player->point);
			free(vars->player);
		}
	}
	return ;
}
