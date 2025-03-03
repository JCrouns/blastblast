/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:58:37 by jait-chd          #+#    #+#             */
/*   Updated: 2025/03/03 02:28:39 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void fix_ber_file(char **v)
{
    int i;

    i = 0 ;
    while(v[1][i])
        i++;
    i--;
    while(v[1][i])
    {
        i++;
        if(v[1][i - 1] != 'r' || v[1][i - 2] != 'e' || v[1][i - 3] != 'b' || v[1][i - 4] != '.' )
            write(2 , "error : invalid map file(.ber problem)\n" ,39 );
    }


}

int	main(int c, char **v)
{
	int				i;
	t_crouns_game	game;

	check_argc(c);
  //  fix_ber_file(v[1]);
	init_game(&game);
	read_map_count_rows_cols(&game, v[1]);
	allocate_map_on_heap(&game, v[1]);
	process_map(game);
	// print_map(&game);
	find_player_positions(&game);
    mlx_stuff(&game);
}
