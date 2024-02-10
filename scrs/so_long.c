/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:27:22 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 15:08:51 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	*vars_init(t_map *map, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		return (NULL);
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (NULL);
	vars->win = mlx_new_window(vars->mlx, \
		BASE_SIZE * (map->width), BASE_SIZE * (map->height), argv[0]);
	vars->map = map;
	vars->score = 0;
	vars->flag = 0;
	return (vars);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_vars	*vars;

	if (argc != 2)
		so_long_exit_wout_errorno("arg error", NULL, NULL);
	map = so_long_read_map(argv[1]);
	if (map == NULL)
		so_long_exit_wout_errorno("map error", NULL, NULL);
	vars = vars_init(map, argv);
	if (vars == NULL)
		so_long_exit_wout_errorno("vars init error", map, NULL);
	so_long_exec_game(vars);
	return (0);
}
