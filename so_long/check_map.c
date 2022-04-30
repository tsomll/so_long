/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:03:28 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 16:03:30 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_game *game, int i, int j)
{
	if ((i == 0 || i + 1 == game->map->height) \
	&& game->map->map[i][j] != '1')
	{
		write(1, "The wall is open!\n", 18);
		return (0);
	}
	if ((j == 0 || j + 1 == game->map->width)
		&& game->map->map[i][j] != '1')
	{
		write(1, "The wall is open!\n", 18);
		return (0);
	}
	return (1);
}

void	check_elem1(t_game *game, int *count, int i, int j)
{
	if (game->map->map[i][j] == 'P')
	{
		count[0]++;
		game->player_x = j;
		game->player_y = i;
	}
	if (game->map->map[i][j] == 'C')
	{
		count[1]++;
		game->map->coin++;
	}
	if (game->map->map[i][j] == 'E')
	{
		count[2]++;
		game->exit_x = j;
		game->exit_y = i;
	}
}

int	check_elem2(int point)
{
	if (point != 'P' && point != 'C' && point != 'E' && point != '1' \
	&& point != '0')
	{
		write(1, "incorrect element!\n", 19);
		return (0);
	}
	return (1);
}

int	check_elem3(int *count)
{
	if (count[0] != 1 || count[1] < 1 || count[2] != 1)
	{
		write(1, "incorrect number of elements!\n", 30);
		return (0);
	}
	return (1);
}

int	check(t_game *game)
{
	int	i;
	int	j;
	int	count[3];

	i = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (game->map->map[i][j])
		{
			check_elem1(game, count, i, j);
			if (!check_wall(game, i, j) || !check_elem2(game->map->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (!check_elem3(count))
		return (0);
	return (1);
}
