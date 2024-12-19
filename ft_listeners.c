/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listeners.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:02:20 by luinasci          #+#    #+#             */
/*   Updated: 2024/12/16 17:51:13 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_on_destroy(t_data *data)
{
	mlx_destroy_window (data->mlx, data->win);
	mlx_destroy_display (data->mlx);
	free (data->mlx);
	exit (0);
	return (0);
}

int	ft_on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("You've pressed: %d\\n", keysym);
	return (0);
}
