/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:22:54 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 16:22:56 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *n)
{
	int	s;

	s = 0;
	while (*n != '\0')
	{
		n++;
		s++;
	}
	return ((size_t)s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*src;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	src = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (src == NULL)
		return (NULL);
	while (s1[k] != '\0')
		src[i++] = s1[k++];
	k = 0;
	while (s2[k] != '\0')
		src[i++] = s2[k++];
	src[i] = '\0';
	free (s1);
	return (src);
}

char	*ft_strchr(const char *src)
{
	char	*s2;

	s2 = (char *)src;
	while (*s2 != '\0' && *s2 != '\n')
		s2++;
	if (*s2 == '\0')
		return (NULL);
	return (s2);
}

char	*ft_fd_read(int fd, char *ost)
{
	char	*buf;
	int		kol;

	kol = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(ost) && kol != 0)
	{
		kol = read(fd, buf, BUFFER_SIZE);
		if (kol < 1 && *ost == '\0')
		{
			free(ost);
			free(buf);
			buf = 0;
			return (NULL);
		}
		buf[kol] = '\0';
		ost = ft_strjoin(ost, buf);
	}
	free (buf);
	buf = 0;
	return (ost);
}

char	*ft_line(char *ost)
{
	int		i;
	char	*str;

	i = 0;
	if (ost[i] == '\0')
		return (NULL);
	while (ost[i] != '\0' && ost[i] != '\n')
		i++;
	if (ost[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (ost[i] != '\0' && ost[i] != '\n')
	{
		str[i] = ost[i];
		i++;
	}
	if (ost[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}
