/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:44:42 by nuno              #+#    #+#             */
/*   Updated: 2022/09/16 17:05:55 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_msg_free_exit(char *message, char *to_free)
{
	ft_putendl_fd(message, 2);
	free(to_free);
	to_free = NULL;
	exit(0);
}

void	error_msg_exit(char *message)
{
	ft_putendl_fd(message, 2);
	exit(0);
}

void	check_arg(int argc, char *map_filename)
{
	if (argc != 2)
		error_msg_exit("Error: Arguments must be 2");
	if (ft_strlen(map_filename) < 6 || !ft_strrchr(map_filename, '.'))
		error_msg_exit("Error: Invalid argument");
	if (ft_strcmp(ft_strrchr(map_filename, '.'), ".ber") != 0)
		error_msg_exit("Error: File must be of type \"<name>.ber\"");
}
