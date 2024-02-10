/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:27:45 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/10 16:22:28 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BASE_SIZE 32

# define SUCCESS 0
# define FAILURE -1

# ifdef __linux__
#  include "keymap_linux.h"
# elif __APPLE__
#  include "keymap_mac.h"
# else
#  error "Unsupported operating system"
# endif

# include <stdio.h> // size_t, NULL, printf, perror
# include <unistd.h>
// read, write, close, access, dup, dup2, execve, fork, pipe, unlink
# include <stdlib.h> // size_t, NULL, malloc, free, exit
# include <fcntl.h> // open, O_RDONLY
# include <limits.h> // INT_MAX
# include <errno.h> // errno
# include <string.h> // strerror
# include "libft.h" // libft
# include "mlx.h" // mlx

typedef struct s_map {
	int		width;
	int		height;
	char	**structure;
}			t_map;

typedef struct s_point {
	int			x;
	int			y;
}				t_point;

typedef struct s_sprite {
	void		*reference;
	int			size;
}				t_sprite;

typedef struct s_player {
	t_sprite	*sprite;
	t_point		*point;
	int			dir;
}				t_player;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
	int			score;
	int			flag;
}				t_vars;

// so_long.c
t_vars	*vars_init(t_map *map, char **argv);
int		main(int argc, char *argv[]);

// so_long_read_map.c
int		so_long_add_line(t_map *map, char *line);
t_map	*so_long_read_map(char *file);
// so_long_map_valid.c
int		so_long_map_length_update(t_map *map, char *line);
int		so_long_map_char_valid(t_map map);
int		so_long_map_key_count(t_map map, char *c);
int		so_long_map_post_valids(t_map map);
// so_long_map_valid_algorithm.c
int		so_long_fill_next_block(t_map *map, \
			int x_position, int y_position, int dir);
int		so_long_flood_fill(t_map *map);
t_map	*so_long_copy_map(t_map map);
int		so_long_map_route_check(t_map map);

// so_long_exec.c
void	so_long_exec_game(t_vars *vars);

// so_long_sprite.c
void	so_long_put_walls(t_vars *vars);
void	so_long_put_fields_all(t_vars *vars);
void	so_long_put_pals(t_vars *vars);
void	so_long_put_exit(t_vars *vars);
// so_long_sprite_util.c
void	*so_long_image_wrap(void *xvar, char *file);
void	so_long_put_sprite_wrap(t_vars *vars, t_sprite icon, int i);
// so_long_player_utils.c
t_point	*so_long_search_item(t_map map, char item);
int		so_long_player_init(t_vars *vars);
void	so_long_put_player(t_vars *vars, char *filename);

// so_long_move.c
void	so_long_move_right(t_vars *vars);
void	so_long_move_left(t_vars *vars);
void	so_long_move_up(t_vars *vars);
void	so_long_move_down(t_vars *vars);
// so_long_hook.c
int		so_long_key_hooks(int keycode, t_vars *vars);

// so_long_collection.c
void	so_long_count_score(t_vars *vars);
void	so_long_catch_em(t_vars *vars, t_point *point);

// so_long_free.c
void	so_long_free_map_structure(t_map *map);
void	so_long_free_map(t_map *map);
void	so_long_free_vars(t_vars *vars);

// so_long_exit_and_error.c
void	so_long_exit_with_errorno(char *message, t_map *map, t_vars *vars);
void	so_long_exit_wout_errorno(char *message, t_map *map, t_vars *vars);
void	so_long_exit_noerror(char *message, t_vars *vars);
int		so_long_destroy_wrapper(t_vars *vars);

#endif // SO_LONG_H