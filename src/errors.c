/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:44:42 by nuno              #+#    #+#             */
/*   Updated: 2022/09/30 20:23:40 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_msg_errno_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

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
