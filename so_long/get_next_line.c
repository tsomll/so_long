/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:22:17 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 16:22:19 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char **ost)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while ((*ost)[i] != '\n' && (*ost)[i] != '\0')
		i++;
	if (!(*ost))
	{
		free (*ost);
		*ost = 0;
		return (NULL);
	}
	if ((*ost)[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen((*ost)) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while ((*ost)[i] != '\0')
		str[j++] = (*ost)[i++];
	str[j] = '\0';
	free(*ost);
	*ost = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*ost;

	if (!ost)
	{
		ost = (char *)malloc(sizeof(char ) * 1);
		ost[0] = '\0';
	}
	ost = ft_fd_read(fd, ost);
	if (!ost)
	{
		free (ost);
		return (NULL);
	}
	line = ft_line(ost);
	ost = ft_new_line(&ost);
	if (!line && ost)
	{
		free(ost);
		ost = 0;
	}
	return (line);
}
