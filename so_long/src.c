/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:11:06 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 16:11:09 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_tile(t_game *game, void *tile, int x, int y)
{
	x = x * 32;
	y = y * 32;
	mlx_put_image_to_window(game->mlx, game->win, game->img->land, x, y);
	mlx_put_image_to_window(game->mlx, game->win, tile, x, y);
}

void	clear_memory(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
		free (game->map->map[i++]);
	free(game->map);
	free(game->img);
	free(game);
}

void	del(t_game *game)
{
	clear_memory(game);
	write (1, "Window closed\n", 14);
	exit (0);
}

int	game_close(t_game *game)
{
	del (game);
	exit (0);
}

void	check_result(t_game *game)
{
	if (!check(game))
	{
		clear_memory(game);
		exit(0);
	}
}
