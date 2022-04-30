/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:24:58 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 16:25:00 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	game = (t_game *)malloc(sizeof(t_game) * 1);
	if (argc != 2)
	{
		write (1, "Enter the correct file name\n", 28);
		free (game);
		exit (0);
	}
	else
		game->map_file = argv[1];
	fd = open(game->map_file, O_RDWR);
	init(game);
	map(fd, game);
	check_result(game);
	game->win = mlx_new_window(game->mlx, game->map->width * 32, \
	game->map->height * 32, "super game");
	output(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 1L << 0, game_close, game);
	mlx_loop(game->mlx);
}
