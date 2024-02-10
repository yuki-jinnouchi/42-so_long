/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:16:15 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 16:18:49 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*update map length*/
int	so_long_map_length_update(t_map *map, char *line)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (map->height == 0)
		map->width = line_len;
	else
	{
		if (map->width != line_len)
			return (FAILURE);
	}
	map->height++;
	return (SUCCESS);
}

/*check letters and wall*/
int	so_long_map_char_valid(t_map map)
{
	int	count_x;
	int	count_y;

	count_y = 0;
	while (count_y < map.height)
	{
		count_x = 0;
		while (count_x < map.width)
		{
			if (count_x == 0 || count_x == map.width - 1 || \
				count_y == 0 || count_y == map.height - 1)
			{
				if (ft_strchr("1", map.structure[count_y][count_x]) == NULL)
					return (FAILURE);
			}
			if (ft_strchr("01CEP", map.structure[count_y][count_x]) == NULL)
				return (FAILURE);
			count_x++;
		}
		count_y++;
	}
	return (SUCCESS);
}

/*counter for key chars*/
int	so_long_map_key_count(t_map map, char *c)
{
	int	count_x;
	int	count_y;
	int	count;

	count = 0;
	count_y = 0;
	while (count_y < map.height)
	{
		count_x = 0;
		while (count_x < map.width)
		{
			if (ft_strchr(c, map.structure[count_y][count_x]) != NULL)
				count++;
			count_x++;
		}
		count_y++;
	}
	return (count);
}

int	so_long_map_post_valids(t_map map)
{
	int	count_collectible;

	if (so_long_map_char_valid(map) == FAILURE)
		return (FAILURE);
	if (so_long_map_key_count(map, "P") != 1)
		return (FAILURE);
	if (so_long_map_key_count(map, "E") != 1)
		return (FAILURE);
	count_collectible = so_long_map_key_count(map, "C");
	if (count_collectible < 1)
		return (FAILURE);
	if (so_long_map_route_check(map) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
