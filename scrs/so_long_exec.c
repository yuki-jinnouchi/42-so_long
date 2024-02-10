/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:34:19 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 09:55:55 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_exec_game(t_vars *vars)
{
	t_map		*map;

	map = vars->map;
	so_long_put_fields_all(vars);
	so_long_put_walls(vars);
	if (so_long_player_init(vars) == FAILURE)
		so_long_exit_with_errorno("player malloc error!", map, vars);
	so_long_put_pals(vars);
	so_long_put_player(vars, "textures/02.xpm");
	mlx_key_hook(vars->win, so_long_key_hooks, vars);
	mlx_mouse_hook(vars->win, so_long_mouse_hooks, vars);
	mlx_loop(vars->mlx);
}
