/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:05:55 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 16:05:57 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_out(t_game *game, char point, int j, int i)
{
	if (point == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img->land, i, j);
	if (point == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->wall, i, j);
	if (point == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->land, i, j);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img->player_down, i, j);
	}
	if (point == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->land, i, j);
		mlx_put_image_to_window(game->mlx, game->win, game->img->food, i, j);
	}
	if (point == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->land, i, j);
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit, i, j);
	}
}

void	output(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (game->map->map[i][j])
		{
			draw_out(game, game->map->map[i][j], i * 32, j * 32);
			j++;
		}
		i++;
	}
}
