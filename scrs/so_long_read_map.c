/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:16:15 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 10:03:58 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*check length and renew structure*/
int	so_long_add_line(t_map *map, char *line)
{
	char	*trimmed_line;
	char	**new_ptr;
	int		i;

	trimmed_line = ft_strtrim(line, "\n");
	free(line);
	if (so_long_map_length_update(map, trimmed_line) == FAILURE)
	{
		free(trimmed_line);
		return (FAILURE);
	}
	new_ptr = malloc((map->height + 1) * sizeof(char *));
	i = 0;
	while (i < map->height - 1)
	{
		new_ptr[i] = map->structure[i];
		i++;
	}
	new_ptr[i] = ft_strdup(trimmed_line);
	free(trimmed_line);
	if (map->structure != NULL)
		free(map->structure);
	map->structure = new_ptr;
	return (SUCCESS);
}

t_map	*so_long_map_init(void)
{
	t_map	*map;

	map = malloc (sizeof(t_map));
	map->structure = NULL;
	map->width = 0;
	map->height = 0;
	return (map);
}

t_map	*so_long_read_map(char *file)
{
	t_map	*map;
	int		fd;
	char	*line;

	map = so_long_map_init();
	fd = open(file, O_RDONLY);
	if (fd == 0)
		return (map);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (so_long_add_line(map, line) == FAILURE)
		{
			so_long_free_map(map);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	if (so_long_map_post_valids(*map) == FAILURE)
	{
		so_long_free_map_structure(map);
		map = NULL;
		return (map);
	}
	return (map);
}
