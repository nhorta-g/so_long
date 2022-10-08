/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:32:44 by nuno              #+#    #+#             */
/*   Updated: 2022/10/08 12:34:38 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	create_map_var(t_game *game, char *all_chars)
{
	game->map_height = (game->lines - 1) * 40;
	game->map_width = game->first_line_width * 40;
	game->map = malloc(sizeof(char)
			* (game->lines * game->first_line_width) + 1);
	ft_strlcpy(game->map, all_chars, (game->lines * game->first_line_width));
	game->fd = close(game->fd);
	free(all_chars);
	all_chars = 0;
}

void	no_line(t_game *game, int last_wall, char *all_chars, char *line)
{
	game->lines++;
	if (last_wall)
		error_msg_free_exit
		("Error\nLast line of characters not walls.", all_chars);
	free(line);
	line = 0;
}

void	gnl_body(t_game *game, char *all_chars, char *line, int lenght)
{
	int	last_wall;

	last_wall = 1;
	while (line)
	{
		game->lines++;
		ft_strcat(all_chars, line);
		free(line);
		line = get_next_line(game->fd);
		lenght = ft_strlen(line);
		if (line)
			last_wall = check_wall(line);
		if (line && (line[0] != '1' || line[lenght - 1] != '1'))
			error_msg_free_exit("One line has no exterior wall", all_chars);
		if (line && (strlen(line)
				!= (long unsigned int)game->first_line_width))
			error_msg_free_exit
				("One line has different width than the first", all_chars);
		if (!line)
			no_line(game, last_wall, all_chars, line);
	}
}

void	init_map(t_game *game, char *map_file_name)
{
	char	*line;
	char	*all_chars;
	int		lenght;

	lenght = 0;
	game->fd = open(map_file_name, O_RDONLY);
	if (game->fd == -1)
		error_msg_exit("Error: file can't be read");
	line = get_next_line(game->fd);
	if (check_wall(line))
		error_msg_free_exit("Error\nFirst line of characters not walls", line);
	game->first_line_width = ft_strlen(line);
	all_chars = (char *)malloc(10000 * sizeof(char));
	if (!all_chars)
		error_msg_exit("Couldn't allocate memory for all_chars variable");
	*all_chars = 0;
	game->lines = 0;
	gnl_body(game, all_chars, line, lenght);
	check_characters1(game, all_chars);
	create_map_var(game, all_chars);
}

void	init_struc(t_game *game)
{
	game->nb_exit = 0;
	game->numb_move = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx,
			game->map_width, game->map_height, "so_long");
	game->mlx.mlx_img = mlx_new_image
		(game->mlx.mlx, game->map_width, game->map_height);
	texture_init(game);
}
