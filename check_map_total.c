/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_total.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:57:08 by jait-chd          #+#    #+#             */
/*   Updated: 2025/03/02 00:57:12 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_invalid_map(void)
{
	write(2, "error : invalid map\n", 20);
	exit(1);
}

void	map_check_wall(t_crouns_game game)
{
	int	c;
	int	r;

	c = 0;
	while (c < game.cols)
	{
		if (game.map[0][c] != WALL || game.map[game.rows - 1][c] != WALL)
			error_invalid_map();
		c++;
	}
	r = 0;
	while (r < game.rows)
	{
		if (game.map[r][0] != WALL || game.map[r][game.cols - 1] != WALL)
			error_invalid_map();
		r++;
	}
}

void	map_check_player(t_crouns_game game)
{
	int	player_count;
	int	r;
	int	c;

	player_count = 0;
	r = 0;
	while (r < game.rows)
	{
		c = 0;
		while (c < game.cols)
		{
			if (game.map[r][c] == PLAYER)
			{
				player_count++;
			}
			c++;
		}
		r++;
	}
	if (player_count != 1)
	{
		error_invalid_map();
	}
}

void	map_check_collectables(t_crouns_game game)
{
	int	collectable_count;
	int	total_collectables;
	int	r;
	int	c;

	collectable_count = 0;
	total_collectables = 0;
	r = 0;
	while (r < game.rows)
	{
		c = 0;
		while (c < game.cols)
		{
			if (game.map[r][c] == COLLECTABLE)
			{
				collectable_count++;
			}
			c++;
		}
		r++;
	}
	if (collectable_count < 1)
		error_invalid_map();
	total_collectables = collectable_count;
}

void	invalid_chars(t_crouns_game game)
{
	int		r;
	int		c;
	char	ch;

	r = 0;
	while (r < game.rows)
	{
		c = 0;
		while (c < game.cols)
		{
			ch = game.map[r][c];
			if (ch != PLAYER && ch != COLLECTABLE && ch != WALL && ch != SPACE
				&& ch != EXIT)
				error_invalid_map();
			c++;
		}
		r++;
	}
}

void	process_map(t_crouns_game game)
{
	map_check_wall(game);
	map_check_player(game);
	map_check_collectables(game);
	invalid_chars(game);
}
