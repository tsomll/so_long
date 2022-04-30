/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:59:00 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 15:59:06 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game	*game)
{
	int	img_width;
	int	img_height;

	game->img->player_down = mlx_xpm_file_to_image(game->mlx, \
	"images/pdown.xpm", &img_width, &img_height);
	game->img->player_up = mlx_xpm_file_to_image(game->mlx, \
	"images/pup.xpm", &img_width, &img_height);
	game->img->player_left = mlx_xpm_file_to_image(game->mlx, \
	"images/pright.xpm", &img_width, &img_height);
	game->img->player_right = mlx_xpm_file_to_image(game->mlx, \
	"images/pleft.xpm", &img_width, &img_height);
	game->img->wall = mlx_xpm_file_to_image(game->mlx, \
	"images/plitka.xpm", &img_width, &img_height);
	game->img->land = mlx_xpm_file_to_image(game->mlx, \
	"images/blablatrava.xpm", &img_width, &img_height);
	game->img->exit = mlx_xpm_file_to_image(game->mlx, \
	"images/doorClose2.0.xpm", &img_width, &img_height);
	game->img->exit2 = mlx_xpm_file_to_image(game->mlx, \
	"images/doorOpen2.0.xpm", &img_width, &img_height);
	game->img->food = mlx_xpm_file_to_image(game->mlx, \
	"images/eda2.0.xpm", &img_width, &img_height);
}

void	init(t_game	*game)
{
	game->map = (t_map *)malloc(sizeof(t_map) * 1);
	game->img = (t_img *)malloc(sizeof(t_img) * 1);
	game->mlx = mlx_init();
	game->score = 0;
	game->map->coin = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->player_y = 0;
	game->player_x = 0;
	game->steps = 0;
	init_img(game);
}
