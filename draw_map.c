/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:40:15 by jait-chd          #+#    #+#             */
/*   Updated: 2025/03/03 02:24:48 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_crouns_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == WALL)
				game->img = mlx_xpm_file_to_image(game->mlx,
						"textures/wall.xpm", &game->width, &game->height);
			else if (game->map[y][x] == SPACE)
				game->img = mlx_xpm_file_to_image(game->mlx,
						"textures/empty.xpm", &game->width, &game->height);
			else if (game->map[y][x] == PLAYER)
				game->img = mlx_xpm_file_to_image(game->mlx,
						"textures/lufy1.xpm", &game->width, &game->height);
			else if (game->map[y][x] == COLLECTABLE)
				game->img = mlx_xpm_file_to_image(game->mlx,
						"textures/fruit.xpm", &game->width, &game->height);
			else if (game->map[y][x] == EXIT)
				game->img = mlx_xpm_file_to_image(game->mlx,
						"textures/exit.xpm", &game->width, &game->height);
			else
				game->img = NULL;
			if (game->img)
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, x* 64, y * 64);
				mlx_destroy_image(game->mlx, game->img);
			}
			else
				write(2, "Error: Could not load image\n", 27);
			x++;
		}
		y++;
	}
}
