/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:03:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 15:36:59 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_exit_with_errorno(char *message, t_map *map, t_vars *vars)
{
	ft_putstr_fd("Error. ", 1);
	ft_putstr_fd(message, 1);
	mlx_destroy_display(vars->mlx);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	if (map != NULL)
		so_long_free_map(map);
	so_long_free_map(map);
	so_long_free_vars(vars);
	if (errno)
		exit (errno);
	exit (EXIT_FAILURE);
}

void	so_long_exit_wout_errorno(char *message, t_map *map, t_vars *vars)
{
	ft_putstr_fd("Error. ", 1);
	ft_putstr_fd(message, 1);
	if (map != NULL)
		so_long_free_map(map);
	if (vars != NULL)
	{
		mlx_destroy_display(vars->mlx);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		so_long_free_vars(vars);
	}
	exit (EXIT_FAILURE);
}

void	so_long_exit_noerror(char *message, t_vars *vars)
{
	ft_putstr_fd(message, 1);
	mlx_destroy_display(vars->mlx);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	so_long_free_vars(vars);
	exit (EXIT_SUCCESS);
}

int	so_long_destroy_wrapper(t_vars *vars)
{
	so_long_exit_noerror("destroyed! seeya!", vars);
	return (SUCCESS);
}
