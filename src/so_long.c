/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:46:34 by nuno              #+#    #+#             */
/*   Updated: 2022/11/09 15:17:16 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_arg(argc, argv[1]);
	init_map(&game, argv[1]);
	init_struc(&game);
	draw_map(&game);
	mlx_hook(game.mlx.mlx_win, 02, 1L << 0, key_hook, &game);
	mlx_hook(game.mlx.mlx_win, 17, 1L << 2, exit_hook, &game);
	mlx_loop(game.mlx.mlx);
}
