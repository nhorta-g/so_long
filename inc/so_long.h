/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:02:21 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/09/16 17:43:33 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_game
{
	int		fd;
}				t_game;

void	init_map(char *map_file_name, t_game *game);
void	check_arg(int argc, char *argv);
void	check_wall(char *line);
void	error_msg_exit(char *message);
void	error_msg_free_exit(char *message, char *to_free);
char	*get_next_line(int fd);

#endif
