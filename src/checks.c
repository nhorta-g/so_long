/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:37:53 by nuno              #+#    #+#             */
/*   Updated: 2022/10/08 13:03:38 by nuno             ###   ########.fr       */
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
		error_msg_exit("Error\nArguments must be 2\n");
	if (ft_strlen(map_filename) < 5)
		error_msg_exit("Error\nFilename has to have at least 4 characters\n");
	if (ft_strcmp(ft_strrchr(map_filename, '.'), ".ber") != 0)
		error_msg_exit("Error\nFile must be of type \"<name>.ber\"\n");
}

void	check_characters2(char *all_chars)
{
	int	i;
	int	count_p;
	int	count_e;

	i = 0;
	count_p = 0;
	count_e = 0;
	while (all_chars[i])
	{
		if (all_chars[i] == 'P')
			count_p++;
		if (all_chars[i] == 'E')
			count_e++;
		if ((all_chars[i] != '1') && (all_chars[i] != '0')
			&& (all_chars[i] != 'E') && (all_chars[i] != 'P')
			&& (all_chars[i] != 'C'))
			error_msg_free_exit
			("Error\nMap chars must be 1, 0, E, P, C\n", all_chars);
		i++;
	}
	if (count_p > 1)
		error_msg_free_exit("Error\nMore than one player.\n", all_chars);
	if (count_e > 1)
		error_msg_free_exit("Error\nMore than one exit.\n", all_chars);
}

void	check_characters1(t_game *game, char *all_chars)
{
	if ((ft_strchr(all_chars, 'P') == NULL)
		|| (ft_strchr(all_chars, 'E') == NULL)
		|| (ft_strchr(all_chars, 'C') == NULL))
		error_msg_free_exit
		("Error\nMissing one player, one collectible or one exit\n", all_chars);
	if (game->first_line_width == game->lines)
		error_msg_free_exit("Error\nMap is a square.\n", all_chars);
	check_characters2(all_chars);
}
