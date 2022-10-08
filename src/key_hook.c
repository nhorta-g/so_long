/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:55:48 by edjavid           #+#    #+#             */
/*   Updated: 2022/10/08 14:41:08 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_hook(t_game *game)
{
	free(game->map);
	exit(1);
}

int	reduce_window(t_game *game)
{
	draw_map(game);
	return (1);
}

void	is_game_finished(t_game *game)
{
	if (ft_strchr(game->map, 'E') == NULL)
	{
		if (game->nb_exit == 1)
			if (ft_strchr(game->map, 'X') == NULL)
				game_over(game, "You won!\n");
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (ft_strchr(game->map, 'C') == NULL)
	{
		while (ft_strchr(game->map, 'E'))
		{
			game->nb_exit++;
			*ft_strchr(game->map, 'E') = 'X';
		}
	}
	if (keycode == 65307)
		game_over(game, "Escape pressed, goodbye!\n");
	if (keycode == 115)
		move_bottom(game);
	if (keycode == 119)
		move_up(game);
	if (keycode == 100)
		move_right(game);
	if (keycode == 97)
		move_left(game);
	is_game_finished(game);
	draw_map(game);
	return (1);
}
