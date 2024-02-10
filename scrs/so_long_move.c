/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:34:19 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 12:55:46 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_move_right(t_vars *vars)
{
	t_point	*point;
	t_map	*map;

	point = vars->player->point;
	map = vars->map;
	if (map->structure[point->y][point->x + 1] != '1')
	{
		point->x += 1;
		so_long_count_score(vars);
	}
	if (map->structure[point->y][point->x] == 'C')
		so_long_catch_em(vars, point);
	if (vars->flag == 1 && map->structure[point->y][point->x] == 'E')
		so_long_exit_noerror("Omedeto! (Congrats!)", vars);
	so_long_put_fields_all(vars);
	so_long_put_pals(vars);
	so_long_put_exit(vars);
	if (point->x % 2 == 0)
		so_long_put_player(vars, "textures/09.xpm");
	else
		so_long_put_player(vars, "textures/10.xpm");
}

void	so_long_move_left(t_vars *vars)
{
	t_point	*point;
	t_map	*map;

	point = vars->player->point;
	map = vars->map;
	if (map->structure[point->y][point->x - 1] != '1')
	{
		point->x -= 1;
		so_long_count_score(vars);
	}
	if (map->structure[point->y][point->x] == 'C')
		so_long_catch_em(vars, point);
	if (vars->flag == 1 && map->structure[point->y][point->x] == 'E')
		so_long_exit_noerror("Omedeto! (Congrats!)", vars);
	so_long_put_fields_all(vars);
	so_long_put_pals(vars);
	so_long_put_exit(vars);
	if (point->x % 2 == 0)
		so_long_put_player(vars, "textures/07.xpm");
	else
		so_long_put_player(vars, "textures/08.xpm");
}

void	so_long_move_up(t_vars *vars)
{
	t_point	*point;
	t_map	*map;

	point = vars->player->point;
	map = vars->map;
	if (map->structure[point->y - 1][point->x] != '1')
	{
		point->y -= 1;
		so_long_count_score(vars);
	}
	if (map->structure[point->y][point->x] == 'C')
		so_long_catch_em(vars, point);
	if (vars->flag == 1 && map->structure[point->y][point->x] == 'E')
		so_long_exit_noerror("Omedeto! (Congrats!)", vars);
	so_long_put_fields_all(vars);
	so_long_put_pals(vars);
	so_long_put_exit(vars);
	if (point->y % 2 == 0)
		so_long_put_player(vars, "textures/04.xpm");
	else
		so_long_put_player(vars, "textures/06.xpm");
}

void	so_long_move_down(t_vars *vars)
{
	t_point	*point;
	t_map	*map;

	point = vars->player->point;
	map = vars->map;
	if (map->structure[point->y + 1][point->x] != '1')
	{
		point->y += 1;
		so_long_count_score(vars);
	}
	if (map->structure[point->y][point->x] == 'C')
		so_long_catch_em(vars, point);
	if (vars->flag == 1 && map->structure[point->y][point->x] == 'E')
		so_long_exit_noerror("Omedeto! (Congrats!)", vars);
	so_long_put_fields_all(vars);
	so_long_put_pals(vars);
	so_long_put_exit(vars);
	if (point->y % 2 == 0)
		so_long_put_player(vars, "textures/01.xpm");
	else
		so_long_put_player(vars, "textures/03.xpm");
}
