/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:27:12 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 16:27:14 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		player;
	int		wall;
	int		coin;
}	t_map;

typedef struct s_img
{
	void	*player_right;
	void	*player_left;
	void	*player_up;
	void	*player_down;
	void	*wall;
	void	*land;
	void	*food;
	void	*exit;
	void	*exit2;

}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*map_file;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		steps;
	int		score;

	t_map	*map;
	t_img	*img;
}	t_game;

void	init(t_game *game);
void	map(int fd, t_game *game);
int		check(t_game *game);
void	output(t_game *game);
void	ft_draw_tile(t_game *game, void *tile, int x, int y);
void	del(t_game *game);
void	clear_memory(t_game *game);
void	ft_move_player(t_game *game, int x, int y, int button);
int		key_hook(int key, t_game *game);
void	draw_out(t_game *game, char point, int i, int j);
int		game_close(t_game *game);
void	ft_steps(t_game *game);
void	check_result(t_game *game);
#endif //SO_LONG_H
