/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:44:42 by nuno              #+#    #+#             */
/*   Updated: 2022/10/08 14:13:21 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_msg_free_exit(char *message, char *to_free)
{
	ft_putendl_fd(message, 2);
	free(to_free);
	to_free = NULL;
	exit(EXIT_FAILURE);
}

void	error_msg_exit(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	error_msg_free_map_exit(char *message, t_game *game)
{
	ft_putendl_fd(message, 2);
	free(game->map);
	game->map = NULL;
	exit(EXIT_FAILURE);
}

void	free_so_long(t_game *game)
{
	mlx_destroy_image(game->mlx.mlx, game->player);
	mlx_destroy_image(game->mlx.mlx, game->exit);
	mlx_destroy_image(game->mlx.mlx, game->collectible);
	mlx_destroy_image(game->mlx.mlx, game->tree);
	mlx_destroy_image(game->mlx.mlx, game->ground);
	mlx_destroy_display(game->mlx.mlx);
	free(game->map);
	free(game->mlx.mlx);
	free(game->mlx.mlx_img->image);
	free(game->mlx.mlx_img);
}

void	game_over(t_game *game, char *message)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	ft_putstr_fd(message, 1);
	free_so_long(game);
	exit(EXIT_SUCCESS);
}
