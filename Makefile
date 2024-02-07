# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 12:01:36 by gde-sa            #+#    #+#              #
#    Updated: 2024/02/07 12:35:19 by gde-sa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#								  CONFIGURATION				       			   #
#******************************************************************************#
NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -g3 -Wextra -Wall -Werror
LIBMLX = ./MLX42
LIBFT = ./libft

HEADERS	= -I ./mandatory/include -I ./MLX42/include -I ./libft
HEADERS_BONUS	= -I ./bonus/include -I ./MLX42/include -I ./libft
LIBS = ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm ./libft/libft.a

#******************************************************************************#
#				     				FILES      								   #
#******************************************************************************#

MANDATORY = mandatory/

FILES = \
		so_long.c\
		ft_so_long_utils.c\
		clear_memory.c\
		requirements/ft_valid_args.c\
		requirements/ft_valid_score.c\
		requirements/ft_valid_requirements.c\
		map/ft_map.c\
		map/ft_valid_map.c\
		map/ft_valid_walls.c\
		map/ft_valid_flood_flill.c\
		game/ft_game.c\
		game/ft_create_windows.c\
		game/ft_moviments.c\
		game/ft_check_obstacle.c\
		game/ft_check_collectible.c\
		game/ft_move_player.c\
		game/ft_exit.c\

MANDATORY_FINAL = $(addprefix $(MANDATORY),$(FILES))

OBJS= $(MANDATORY_FINAL:.c=.o)

SRC_BONUS = bonus/

FILES_BONUS = \
		so_long_bonus.c\
		ft_so_long_utils_bonus.c\
		clear_memory_bonus.c\
		requirements_bonus/ft_valid_args_bonus.c\
		requirements_bonus/ft_valid_score_bonus.c\
		requirements_bonus/ft_valid_requirements_bonus.c\
		map_bonus/ft_map_bonus.c\
		map_bonus/ft_valid_map_bonus.c\
		map_bonus/ft_valid_walls_bonus.c\
		map_bonus/ft_valid_flood_flill_bonus.c\
		game_bonus/ft_game_bonus.c\
		game_bonus/ft_create_windows_bonus.c\
		game_bonus/ft_moviments_bonus.c\
		game_bonus/ft_check_obstacle_bonus.c\
		game_bonus/ft_check_collectible_bonus.c\
		game_bonus/ft_move_player_bonus.c\
		game_bonus/ft_exit_bonus.c\
		game_bonus/ft_enemy_bonus.c\
		
BONUS_FINAL = $(addprefix $(SRC_BONUS),$(FILES_BONUS))

BONUS_OBJS= $(BONUS_FINAL:.c=.o)

#******************************************************************************#
#				     				RULES      								   #
#******************************************************************************#

all: libft/libft.a ./MLX42/build/libmlx42.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

bonus: libft/libft.a ./MLX42/build/libmlx42.a $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(HEADERS_BONUS) $(LIBS) -o $(NAME_BONUS)

libft/libft.a:
	@make -sC ./libft

./MLX42/build/libmlx42.a:
	@cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@make clean -sC ./libft

fclean: clean
	@cd libft && $(MAKE) fclean
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all, clean, fclean, re, bonus