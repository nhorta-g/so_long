/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:37:56 by nuno              #+#    #+#             */
/*   Updated: 2022/10/08 13:02:22 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	texture_load(t_game *game, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(game->mlx.mlx, path, &width, &height);
	if (*img == 0)
		error_msg_free_map_exit("Error\nCan't load texture\n", game);
	(*img)->width = width;
	(*img)->height = height;
}

void	texture_init(t_game *game)
{
	texture_load(game, &game->player, "./img/link1.xpm");
	texture_load(game, &game->exit, "./img/tent.xpm");
	texture_load(game, &game->collectible, "./img/key.xpm");
	texture_load(game, &game->tree, "./img/tree.xpm");
	texture_load(game, &game->ground, "./img/ground.xpm");
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}
