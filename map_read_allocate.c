/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_allocate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:58:01 by jait-chd          #+#    #+#             */
/*   Updated: 2025/03/02 01:09:07 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_argc(int c)
{
	if (c != 2)
	{
		write(2, "error : Number of args not on point\n", 36);
		exit(1);
	}
}

int	open_file(char *file_name)
{
	int	file_d;

	file_d = open(file_name, O_RDONLY);
	if (file_d < 0)
	{
		write(2, "error : error on opining file\n", 30);
		exit(1);
	}
}

void	read_map_count_rows_cols(t_crouns_game *game, char *file_name)
{
	char	*line;

	game->fd = open_file(file_name);
	line = get_next_line(game->fd);
	while (line != NULL)
	{
		game->rows++;
		if (game->cols == 0)
		{
			game->cols = strlen(line) - 1;
		}
		line = get_next_line(game->fd);
		free(line);
	}
	close(game->fd);
}

void	allocate_map_on_heap(t_crouns_game *game, char *file_name)
{
	char	*line;
	int		r;

	r = 0;
	game->fd = open_file(file_name);
	game->map = (char **)malloc(sizeof(char *) * game->rows);
	if (!game->map)
	{
		write(2, "Error : allocating memory for map\n", 35);
		exit(1);
	}
	while ((line = get_next_line(game->fd)) !=  NULL)
	{
		game->map[r] = strdup(line);
		free(line);
		r++;
	}
	close(game->fd);
}
