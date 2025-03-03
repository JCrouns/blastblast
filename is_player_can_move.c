/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_player_can_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:57:42 by jait-chd          #+#    #+#             */
/*   Updated: 2025/03/03 02:58:16 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_crouns_game *game, int new_row, int new_col, char direction)
{
	if (direction == 'W' && new_row > 0 && game->map[new_row
		- 1][new_col] != WALL)
	{
		return (1);
	}
	else if (direction == 'S' && new_row < game->rows - 1 && game->map[new_row
		+ 1][new_col] != WALL)
	{
		return (1);
	}
	else if (direction == 'A' && new_col > 0 && game->map[new_row][new_col
		- 1] != WALL)
	{
		return (1);
	}
	else if (direction == 'D' && new_col < game->cols - 1
		&& game->map[new_row][new_col + 1] != WALL)
	{
		return (1);
	}
	return (0);
}

void	move_and_eat(t_crouns_game *game, int new_row, int new_col)
{
    if (game->map[new_row][new_col] == COLLECTABLE)
	{
		game->collected_fruits++;
    }
     if(game->map[new_row][new_col] == EXIT)
          exit(1);

	game->map[game->player_r_pos][game->player_c_pos] = SPACE;
	game->player_r_pos = new_row;
	game->player_c_pos = new_col;
	game->map[game->player_r_pos][game->player_c_pos] = PLAYER;
}

int	move_player(t_crouns_game *game, char direction)
{
	int	new_row;
	int	new_col;

	new_row = game->player_r_pos;
	new_col = game->player_c_pos;
	if (can_move(game, new_row, new_col, direction))
	{
		if (direction == 'W')
		{
			new_row--;
		}
		else if (direction == 'S')
		{
			new_row++;
		}
		else if (direction == 'A')
		{
			new_col--;
		}
		else if (direction == 'D')
		{
			new_col++;
		}
		move_and_eat(game, new_row, new_col);
		return (1);
	}
	return (0);
}
