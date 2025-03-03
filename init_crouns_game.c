/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_crouns_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:57:32 by jait-chd          #+#    #+#             */
/*   Updated: 2025/03/02 00:57:33 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_crouns_game *game)
{
	game->fd = 0;
	game->map = NULL;
	game->rows = 0;
	game->cols = 0;
	game->player_r_pos = 0;
	game->player_c_pos = 0;
	game->collected_fruits = 0;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->img = NULL;
	game->width = 64;
	game->height = 64;
}
