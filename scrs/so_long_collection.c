/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_collection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:16:15 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 15:36:23 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_count_score(t_vars *vars)
{
	vars->score++;
	ft_putstr_fd("score: ", 1);
	ft_putnbr_fd(vars->score, 1);
	ft_putchar_fd('\n', 1);
}

void	so_long_catch_em(t_vars *vars, t_point *point)
{
	t_map	*map;

	map = vars->map;
	vars->score++;
	map->structure[point->y][point->x] = '0';
	ft_putstr_fd("- catch em! -\n", 1);
	if (so_long_search_item(*vars->map, 'C') == NULL)
		vars->flag = 1;
}
