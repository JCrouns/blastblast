/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:56:59 by jait-chd          #+#    #+#             */
/*   Updated: 2025/03/02 23:22:04 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "/usr/include/minilibx-linux/mlx.h"

#define WALL '1'
#define PLAYER 'P'
#define SPACE '0'
#define EXIT 'E'
#define COLLECTABLE 'C'

typedef struct s_crouns_game
{
    int fd;
    char **map;
    int rows;
    int cols;
    int player_r_pos;
    int player_c_pos;
    int collected_fruits;
    void *mlx;
    void *mlx_win;
    int width;
    int height;
    void *img;
    int size_width;
    int size_height;
} t_crouns_game;

void init_game(t_crouns_game *game);
int check_argc(int c);
int open_file(char *file_name);
void read_map_count_rows_cols(t_crouns_game *game , char *file_name);
void allocate_map_on_heap(t_crouns_game *game , char *file_name);
void process_map(t_crouns_game game);
void error_invalid_map(void);
void find_player_positions(t_crouns_game *game);
void print_map(t_crouns_game *game);
int can_move(t_crouns_game *game , int new_row , int new_col , char direction);
void move_and_eat(t_crouns_game *game , int new_row , int new_col);
int move_player(t_crouns_game *game , char direction);
int key_hook_code(int keycode , t_crouns_game *game);
void draw_map(t_crouns_game *game);
void map_size_width_height(t_crouns_game *game);
void mlx_stuff(t_crouns_game *game);
#endif
