/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moviments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:50 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/06 11:52:15 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../libft/libft.h"

void	my_keyhook(mlx_key_data_t keydata, t_game **game)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W && ft_obstacle_up(game) == 0)
			ft_move_up(game);
		if (keydata.key == MLX_KEY_S && ft_obstacle_down(game) == 0)
			ft_move_down(game);
		if (keydata.key == MLX_KEY_A && ft_obstacle_left(game) == 0)
			ft_move_left(game);
		if (keydata.key == MLX_KEY_D && ft_obstacle_right(game) == 0)
			ft_move_right(game);
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window((*game)->mlx);
	if ((*game)->score->count_collectible == 0)
		(*game)->img->exit->enabled = true;
}

void	ft_move(t_game **game)
{
	(*game)->score->count_steps = 0;
	if ((*game)->score->count_collectible >= 1)
		(*game)->img->exit->enabled = false;
	mlx_key_hook((*game)->mlx, (void *)my_keyhook, (void *)game);
}
