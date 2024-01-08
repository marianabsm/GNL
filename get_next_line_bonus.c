/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:21:41 by marianamest       #+#    #+#             */
/*   Updated: 2024/01/02 15:24:55 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	saved[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		while (fd <= FOPEN_MAX && fd > 0 && saved[fd][i])
			saved[fd][i++] = 0;
		return (NULL);
	}
	while (saved[fd][0] || read(fd, saved[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, saved[fd]);
		if (ft_clear(saved[fd]))
			break ;
	}
	return (line);
}
