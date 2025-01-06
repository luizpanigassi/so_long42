/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:24:06 by luinasci          #+#    #+#             */
/*   Updated: 2024/12/17 15:45:33 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	initialize_buffer(int fd, char **receiver_buffer)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(*receiver_buffer);
		*receiver_buffer = NULL;
		return (0);
	}
	if (!*receiver_buffer)
		*receiver_buffer = ft_calloc(1, sizeof(char));
	return (1);
}
