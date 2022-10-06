/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:37:53 by nuno              #+#    #+#             */
/*   Updated: 2022/10/05 17:56:00 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_arg(int argc, char *map_filename)
{
	if (argc != 2)
		error_msg_exit("Error\nArguments must be 2");
	if (ft_strlen(map_filename) < 5)
		error_msg_exit("Error\nFilename has to have at least 4 characters");
	if (ft_strcmp(ft_strrchr(map_filename, '.'), ".ber") != 0)
		error_msg_exit("Error\nFile must be of type \"<name>.ber\"");
}

void	check_characters(t_game *game, char *all_chars)
{
	int	i;
	int	count_p;

	if ((ft_strchr(all_chars, 'P') == NULL)
		|| (ft_strchr(all_chars, 'E') == NULL)
		|| (ft_strchr(all_chars, 'C') == NULL))
		error_msg_free_exit
		("Error\nMissing one player, one collectible or one exit", all_chars);
	if (game->first_line_width == game->lines)
		error_msg_free_exit("Error\nMap is a square.", all_chars);
	i = 0;
	count_p = 0;
	while (all_chars[i])
	{
		if (all_chars[i] == 'P')
			count_p++;
		if ((all_chars[i] != '1') && (all_chars[i] != '0')
			&& (all_chars[i] != 'E') && (all_chars[i] != 'P')
			&& (all_chars[i] != 'C'))
			error_msg_free_exit
			("Error\nMap chars must be 1, 0, E, P, C", all_chars);
		i++;
	}
	if (count_p > 1)
		error_msg_free_exit("Error\nMore than one player.", all_chars);
}
