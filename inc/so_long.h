/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:02:21 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/10/05 18:34:59 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include "../libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_mlx
{
	void	*mlx_win;
	void	*mlx;
	t_img	*mlx_img;
}	t_mlx;

typedef struct	s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct	s_game
{
	t_mlx	mlx;
	int		fd;
	int		first_line_width;
	int		lines;
	int		map_height;
	int		map_width;
	char	*map;
	int		numb;
	int		numb_move;
	int		x;
	int		y;
	char	*player_position;
	int		nb_exit;
	t_img	*ground;
	t_img	*player;
	t_img	*collectible;
	t_img	*tree;
	t_img	*exit;
}	t_game;

void			init_map(t_game *game, char *map_file_name);
void			init_struc(t_game *game);
void			check_arg(int argc, char *argv);
int				check_wall(char *line);
void			check_characters(t_game *game, char *all_chars);
void			error_msg_exit(char *message);
void			error_msg_free_exit(char *message, char *to_free);
char			*get_next_line(int fd);
void			texture_load(t_game *game, t_img **img, char *path);
void			texture_init(t_game *game);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void			move_bottom(t_game *game);
void			move_up(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);
void			draw_map(t_game *game);
void			check_map_elements(char *all_chars);
int				reduce_window(t_game *game);
int				exit_hook(t_game *game);
int				key_hook(int keycode, t_game *game);
void			is_game_finished(t_game *game);

#endif
