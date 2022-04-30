/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:13:14 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 16:13:16 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n)
{
	char		src[12];
	int			i;

	if (n == 0)
		write(1, "0", 1);
	i = 0;
	while (n > 0)
	{
		src[i++] = n % 10 + '0';
		n /= 10;
	}
	while (i > 0)
		write(1, &src[i-- - 1], 1);
}

void	ft_steps(t_game *game)
{
	write(1, "STEP: ", 6);
	game->steps++;
	ft_putnbr(game->steps);
	write(1, "\n", 1);
}

void	ft_move_key(t_game *game, int button)
{
	if (button == 1)
		ft_draw_tile(game, game->img->player_down, \
		game->player_x, game->player_y);
	if (button == 2)
		ft_draw_tile(game, game->img->player_up, \
		game->player_x, game->player_y);
	if (button == 3)
		ft_draw_tile(game, game->img->player_right, \
		game->player_x, game->player_y);
	if (button == 4)
		ft_draw_tile(game, game->img->player_left, \
		game->player_x, game->player_y);
}

void	ft_move_player(t_game	*game, int x, int y, int button)
{
	if (game->map->map[game->player_y + y][game->player_x + x] == '1')
		return ;
	if (game->map->map[game->player_y + y][game->player_x + x] == 'C')
	{
		game->map->map[game->player_y + y][game->player_x + x] = '0';
		game->score++;
	}
	if (game->score == game->map->coin)
		ft_draw_tile(game, game->img->exit2, game->exit_x, game->exit_y);
	if (game->map->map[game->player_y + y][game->player_x + x] == 'E')
	{
		if (game->score == game->map->coin)
			del(game);
		else
			return ;
	}
	ft_draw_tile(game, game->img->land, game->player_x, game->player_y);
	game->player_x += x;
	game->player_y += y;
	ft_steps(game);
	ft_move_key(game, button);
}
