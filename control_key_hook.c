/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:57:20 by jait-chd          #+#    #+#             */
/*   Updated: 2025/03/02 01:02:00 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook_code(int keycode, t_crouns_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
	if (keycode == 122)
	{
		move_player(game, 'W');
	}
	if (keycode == 115)
	{
		move_player(game, 'S');
	}
	if (keycode == 113)
	{
		move_player(game, 'A');
	}
	if (keycode == 100)
	{
		move_player(game, 'D');
	}
	draw_map(game);
	return (0);
}
