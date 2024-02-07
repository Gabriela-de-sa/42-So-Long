/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:06:00 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/06 17:44:57 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define IMG_X 64
# define IMG_Y 64

typedef struct s_image
{
	mlx_image_t		*pirate;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;
	mlx_image_t		*tree;
	mlx_image_t		*background;
	mlx_image_t		*icon_flag;
}	t_image;

typedef struct s_texture
{
	mlx_texture_t		*pirate_t;
	mlx_texture_t		*collectible_t;
	mlx_texture_t		*exit_t;
	mlx_texture_t		*tree_t;
	mlx_texture_t		*background_t;
	mlx_texture_t		*icon_flag;
}	t_texture;

typedef struct s_score
{
	int	count_collectible;
	int	count_collectible_copy;
	int	count_exit;
	int	count_exit_copy;
	int	count_player;
	int	count_tree;
	int	coll_map;
	int	count_steps;
}	t_score;

typedef struct s_game
{
	char			**map;
	char			**map_copy;
	int				cord_x;
	int				cord_y;
	int				x;
	int				y;
	t_score			*score;
	mlx_t			*mlx;
	t_image			*img;
	t_texture		*texture;
}	t_game;

//functions for checking input errors
int		check_extension(char *str);
void	ft_validation_args(int argc, char **argv);
void	ft_check_requirements(char *argv, t_game **game);
void	ft_return_score(t_game **game);
void	ft_validation_caracter(char *buffer, t_game **game, \
		int *count_caracter);
int		ft_score(int file, int *count_caracter, t_game **game);
//utils
int		ft_open_file(char *argv);
size_t	ft_strlen_line(const char *s);
char	*find_line_break(const char *s, int c);
//functions for create matriz and check errors
void	ft_create_matrix(char *argv, t_game **game);
void	ft_check_map(t_game **game);
void	ft_check_walls(t_game **game);
void	ft_flood_fill(t_game **game, int x, int y);
//functions clear memory
void	ft_endgame(t_game **game);
void	ft_message_error(t_game **game);
//game
void	ft_game(t_game **game);
void	ft_windows(t_game **game);
void	ft_move(t_game **game);
int		ft_obstacle_up(t_game **game);
int		ft_obstacle_down(t_game **game);
int		ft_obstacle_left(t_game **game);
int		ft_obstacle_right(t_game **game);
void	ft_collectible(t_game **game);
void	ft_move_up(t_game **game);
void	ft_move_down(t_game **game);
void	ft_move_left(t_game **game);
void	ft_move_right(t_game **game);
void	ft_go_exit(t_game **game);
void	ft_delete_image(t_game **game);
#endif