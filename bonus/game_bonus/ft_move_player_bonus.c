/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:49:28 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/07 11:40:17 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../../libft/libft.h"

void	ft_move_up(t_game **game)
{
	(*game)->img->pirate->instances[0].y -= 64;
	ft_collectible(game);
	ft_enemy(game);
	(*game)->score->count_steps++;
	if ((*game)->score->count_collectible == 0)
		ft_go_exit(game);
}

void	ft_move_down(t_game **game)
{
	(*game)->img->pirate->instances[0].y += 64;
	ft_collectible(game);
	ft_enemy(game);
	(*game)->score->count_steps++;
	if ((*game)->score->count_collectible == 0)
		ft_go_exit(game);
}

void	ft_move_left(t_game **game)
{
	(*game)->img->pirate->instances[0].x -= 64;
	ft_collectible(game);
	ft_enemy(game);
	(*game)->score->count_steps++;
	if ((*game)->score->count_collectible == 0)
		ft_go_exit(game);
}

void	ft_move_right(t_game **game)
{
	(*game)->img->pirate->instances[0].x += 64;
	ft_collectible(game);
	ft_enemy(game);
	(*game)->score->count_steps++;
	if ((*game)->score->count_collectible == 0)
		ft_go_exit(game);
}
