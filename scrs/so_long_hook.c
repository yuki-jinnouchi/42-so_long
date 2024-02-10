/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:34:19 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 10:08:23 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long_key_hooks(int keycode, t_vars *vars)
{
	ft_putnbr_fd(keycode, 1);
	ft_putchar_fd('\n', 1);
	if (keycode == KEY_ESC)
		so_long_exit_noerror("seeya!", vars);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		so_long_move_right(vars);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		so_long_move_left(vars);
	if (keycode == KEY_W || keycode == KEY_UP)
		so_long_move_up(vars);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		so_long_move_down(vars);
	return (SUCCESS);
}

int	so_long_mouse_hooks(int button, t_vars *vars)
{
	if (button == M_RIGHT)
		so_long_move_right(vars);
	if (button == M_LEFT)
		so_long_move_left(vars);
	if (button == M_UP)
		so_long_move_up(vars);
	if (button == M_DOWN)
		so_long_move_down(vars);
	return (SUCCESS);
}
