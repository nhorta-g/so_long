/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:46:34 by nuno              #+#    #+#             */
/*   Updated: 2022/09/16 17:01:53 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i++])
	{
		if (line[i] != '1')
		{
			error_msg_free_exit("First line of characters not walls", line);
		}
	}
}

void	init_map(char *map_file_name, t_game *game)
{
	char *line;

	game->fd = open(map_file_name, O_RDONLY);
	line = get_next_line(game->fd);
	check_wall(line);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_arg(argc, argv[1]);
	init_map(argv[1], &game);
}
