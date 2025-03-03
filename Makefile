EXECUTION_FILE_NAME = so_long
CC = cc
C_FLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC_FILES = check_map_total.c \ control_key_hook.c \ draw_map.c \
			init_crouns_game.c \ is_player_can_move.c \ map_read_allocate.c \
			mlx_stuff.c \

OBJ_FILES = $(SRC: .c =.o)



