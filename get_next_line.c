/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:45:54 by mabrito-          #+#    #+#             */
/*   Updated: 2024/01/02 15:30:55 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	saved[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (saved[i])
			saved[i++] = 0;
		return (NULL);
	}
	while (saved[0] || read(fd, saved, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, saved);
		if (ft_clear(saved))
			break ;
	}
	return (line);
}
