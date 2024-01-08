/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:22:38 by marianamest       #+#    #+#             */
/*   Updated: 2024/01/06 18:42:04 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	int	nl_true;

	i = 0;
	j = 0;
	nl_true = 0;
	while (str[i])
	{
		if (nl_true)
			str[j++] = str[i];
		if (str[i] == '\n')
			nl_true = 1;
		str[i++] = '\0';
	}
	return (nl_true);
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
