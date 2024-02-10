/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check_algorithm.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:16:15 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 16:43:32 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long_fill_next_block(t_map *map, int x_position, int y_position, int dir)
{
	int	flag;
	int	x_next;
	int	y_next;

	flag = 0;
	x_next = x_position;
	y_next = y_position;
	if (dir == 0)
		x_next = x_position - 1;
	if (dir == 1)
		y_next = y_position + 1;
	if (dir == 2)
		x_next = x_position + 1;
	if (dir == 3)
		y_next = y_position - 1;
	if (map->structure[y_position][x_position] == 'P')
	{
		if (map->structure[y_next][x_next] != '1' && \
			map->structure[y_next][x_next] != 'P')
		{
			map->structure[y_next][x_next] = 'P';
			flag = 1;
		}
	}
	return (flag);
}

int	so_long_flood_fill(t_map *map)
{
	int	flag;
	int	x_count;
	int	y_count;

	flag = 1;
	while (flag > 0)
	{
		flag = 0;
		y_count = 0;
		while (y_count++ < map->height - 1)
		{
			x_count = 0;
			while (x_count++ < map->width - 1)
			{
				if (so_long_fill_next_block(map, x_count, y_count, 0) + \
				so_long_fill_next_block(map, x_count, y_count, 1) + \
				so_long_fill_next_block(map, x_count, y_count, 2) + \
				so_long_fill_next_block(map, x_count, y_count, 3) > 0)
					flag = 1;
			}
		}
	}
	if (so_long_map_key_count(*map, "CE") == 0)
		return (SUCCESS);
	return (FAILURE);
}

t_map	*so_long_copy_map(t_map map)
{
	t_map	*map_copy;
	char	**struct_cpy;
	int		i;

	map_copy = malloc(sizeof(t_map));
	if (map_copy == NULL)
		return (NULL);
	struct_cpy = malloc((map.height + 1) * sizeof(char *));
	if (struct_cpy == NULL)
	{
		free(map_copy);
		return (NULL);
	}
	i = 0;
	while (i < map.height)
	{
		struct_cpy[i] = ft_strdup(map.structure[i]);
		i++;
	}
	map.structure[i] = NULL;
	map_copy->structure = struct_cpy;
	map_copy->height = map.height;
	map_copy->width = map.width;
	return (map_copy);
}

/*check if there is a route*/
int	so_long_map_route_check(t_map map)
{
	t_map	*map_copy;
	int		flag;

	map_copy = so_long_copy_map(map);
	if (map_copy == NULL)
		return (FAILURE);
	flag = so_long_flood_fill(map_copy);
	so_long_free_map(map_copy);
	return (flag);
}
