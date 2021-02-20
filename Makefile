##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make
##

SRC		=	src/utility/usage.c\
			src/utility/my_str_to_word_array_sep.c\
			src/initialize/init_ncurses.c\
			src/initialize/load_map.c\
			src/initialize/load_map_misc.c\
			src/initialize/remove_P.c\
			src/initialize/init_global.c\
			src/display/disp_map.c\
			src/display/display_level_completed.c\
			src/display/display_level_completed_misc.c\
			src/display/disp_all.c\
			src/display/display_level_failed.c\
			src/display/display_level_select.c\
			src/game/game_loop.c\
			src/move_player/move_player.c\
			src/move_player/move_player_x.c\
			src/move_player/move_player_y.c\
			src/utility/cpy_ss.c\
			src/display/disp_holes.c\
			src/display/display_menu.c\
			src/display/menu_redirect.c\
			src/display/display_game_state.c\
			src/display/display_exit_screen.c\
			src/utility/char_to_str.c\
			src/utility/ss_to_str.c\
			src/utility/int_to_str.c\
			src/utility/exit_status.c\
			src/game/check_box_movements.c\
			src/game/find_v_nb.c\
			src/error_cases/error_cases_begining.c\
			src/error_cases/error_cases_map.c\
			src/error_cases/error_map_invalid_char.c\
			src/error_cases/error_map_pnb.c\
			src/error_cases/error_boxes_holes.c\

SRC_M	=	src/main.c

SRC_UT	=	tests/*.c

OBJ		=	$(SRC:.c=.o)

OBJ_M	=	$(SRC_M:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

INCLUDE	=	-I./include

NAME	=	beyond_sokoban

NAME_UT	=	unit_tests

CFLAGS	=	-W -Werror -Wall -Wextra -I./include -lncurses -lcsfml-graphics -lcsfml-window -lcsfml-system

CFLAGS_UT	=	-lcriterion --coverage -lgcov

LIB		=	-L lib/ -lmy

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ_M) $(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(OBJ_M) $(INCLUDE) $(CFLAGS) $(LIB)

tests_run:	$(OBJ) $(OBJ_UT)
		make -C lib/my/
		gcc -o $(NAME_UT) $(SRC) $(SRC_UT) $(INCLUDE) $(CFLAGS_UT) $(LIB) -lncurses
		./$(NAME_UT)
		gcovr -e tests

clean:
		$(RM) $(OBJ) $(OBJ_M) lib/my/*.o lib/libmy.a lib/my/libmy.a *gcno *gcda *~

fclean:		clean fclean_ut
		$(RM) $(NAME) tests/*.o

fclean_ut: clean
		$(RM) $(NAME_UT)

re:		fclean all