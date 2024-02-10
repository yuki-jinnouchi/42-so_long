/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:34:19 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 10:03:18 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	*so_long_search_item(t_vars *vars, char item)
{
	int		flag;
	t_point	*point;
	t_map	*map;

	map = vars->map;
	flag = 0;
	point = malloc(sizeof(t_point));
	if (point == NULL)
		return (NULL);
	point->y = 0;
	while (flag != 1 && point->y < map->height)
	{
		point->x = 0;
		while (flag != 1 && point->x < map->width)
		{
			if (map->structure[point->y][point->x] == item)
			{
				flag = 1;
				return (point);
			}
			point->x++;
		}
		point->y++;
	}
	return (NULL);
}

int	so_long_player_init(t_vars *vars)
{
	t_player	*player;
	t_sprite	*sprite;

	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (FAILURE);
	sprite = malloc(sizeof(t_sprite));
	if (sprite == NULL)
		return (FAILURE);
	player->dir = 4;
	vars->player = player;
	vars->player->sprite = sprite;
	player->point = so_long_search_item(vars, 'P');
	if (player->point == NULL)
		return (FAILURE);
	vars->map->structure[player->point->y][player->point->x] = '0';
	return (SUCCESS);
}

void	so_long_put_player(t_vars *vars, char *filename)
{
	int			i;
	t_sprite	*player;
	t_point		*point;
	t_map		*map;

	player = vars->player->sprite;
	point = vars->player->point;
	map = vars->map;
	player->reference = so_long_image_wrap(vars->mlx, filename);
	i = (point->y * map->width) + point->x;
	so_long_put_sprite_wrap(vars, *player, i);
}
