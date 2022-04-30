/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:59:49 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 15:59:51 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map(int fd, int *width, int *height)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	*width = -1;
	*height = 0;
	while (line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		if (*width == -1)
			*width = i;
		if (i != *width)
			exit (0);
		free(line);
		line = get_next_line(fd);
		(*height)++;
	}
}

void	map(int fd, t_game *game)
{
	int	height;
	int	i;
	int	width;
	int	l;

	i = 0;
	count_map(fd, &width, &height);
	game->map->width = width;
	game->map->map = (char **)malloc(sizeof(char *) * (height + 1));
	game->map->height = height;
	close(fd);
	fd = open(game->map_file, O_RDWR);
	while (height-- > 0)
	{
		game->map->map[i++] = get_next_line(fd);
		l = ft_strlen(game->map->map[i - 1]);
		if (game->map->map[i - 1][l - 1] == '\n')
			game->map->map[i - 1][l - 1] = '\0';
	}
}
