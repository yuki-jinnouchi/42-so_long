/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:03:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 09:56:53 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long_exit_with_errorno(char *message, t_map *map, t_vars *vars)
{
	ft_putstr_fd(message, 2);
	so_long_free_map(map);
	so_long_free_vars(vars);
	if (errno)
		exit (errno);
	exit (EXIT_FAILURE);
}

void	so_long_exit_wout_errorno(char *message, t_map *map, t_vars *vars)
{
	ft_putstr_fd(message, 2);
	so_long_free_map(map);
	so_long_free_vars(vars);
	exit (EXIT_FAILURE);
}

void	so_long_exit_noerror(char *message, t_vars *vars)
{
	ft_putstr_fd(message, 1);
	so_long_free_vars(vars);
	exit (EXIT_SUCCESS);
}
