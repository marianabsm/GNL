/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:46:05 by mabrito-          #+#    #+#             */
/*   Updated: 2024/01/02 16:40:16 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *x)
{
	int	i;

	i = 0;
	if (!x)
		return (0);
	while (x[i] && x[i] != '\n')
		i++;
	if (x[i] == '\n')
		i++;
	return (i);
}

int	ft_clear(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (str[i])
	{
		if (flag)
			str[j++] = str[i];
		if (str[i] == '\n')
			flag = 1;
		str[i++] = '\0';
	}
	return (flag);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*prt;

	i = 0;
	j = 0;
	prt = malloc(ft_strlen(s1)+ ft_strlen(s2) + 1);
	if (!prt)
		return (NULL);
	while (s1 && s1[i])
	{
		prt[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		prt[i++] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	prt[i] = '\0';
	return (prt);
}
