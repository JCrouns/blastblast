/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:57:52 by jait-chd          #+#    #+#             */
/*   Updated: 2025/03/02 02:25:19 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*static int key(int i)
{
	printf("%d", i);
}*/
void	mlx_stuff(t_crouns_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (write(2, "error on mlx\n", 13), exit(1));
	game->mlx_win = mlx_new_window(game->mlx, game->cols * 64 , game->rows *64 , "so_long");
	if (!game->mlx_win)
		return (write(2, "error creating window\n", 23), exit(1));
	draw_map(game);
	mlx_key_hook(game->mlx_win, key_hook_code, game);
	mlx_loop(game->mlx);
}
