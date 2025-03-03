/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 02:27:11 by jait-chd          #+#    #+#             */
/*   Updated: 2025/03/03 02:27:13 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_positions(t_crouns_game *game)
{
	int	r;
	int	c;

	r = 0;
	while (r < game->rows)
	{
		c = 0;
		while (c < game->cols)
		{
			if (game->map[r][c] == PLAYER)
			{
				game->player_r_pos = r;
				game->player_c_pos = c;
				return ;
			}
			c++;
		}
		r++;
	}
}
