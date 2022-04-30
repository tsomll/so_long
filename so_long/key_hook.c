/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:20:05 by vvioleta          #+#    #+#             */
/*   Updated: 2022/02/23 16:20:08 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *game)
{
	if (key == 0)
		ft_move_player(game, -1, 0, 3);
	if (key == 1)
		ft_move_player(game, 0, 1, 1);
	if (key == 2)
		ft_move_player(game, 1, 0, 4);
	if (key == 13)
		ft_move_player(game, 0, -1, 2);
	if (key == 53)
		del(game);
	if (key != 0 && key != 1 && key != 2 && key != 13)
		write(1, "OMG! Use only the keys W, A, S, D\n", 34);
	return (0);
}
