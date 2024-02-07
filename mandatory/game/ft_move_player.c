/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:57:08 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/07 11:23:03 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../libft/libft.h"

void	ft_move_up(t_game **game)
{
	(*game)->img->pirate->instances[0].y -= 64;
	ft_collectible(game);
	(*game)->score->count_steps++;
	ft_printf("\nCount Steps: %i", (*game)->score->count_steps);
	if ((*game)->score->count_collectible == 0)
		ft_go_exit(game);
}

void	ft_move_down(t_game **game)
{
	(*game)->img->pirate->instances[0].y += 64;
	ft_collectible(game);
	(*game)->score->count_steps++;
	ft_printf("\nCount Steps: %i", (*game)->score->count_steps);
	if ((*game)->score->count_collectible == 0)
		ft_go_exit(game);
}

void	ft_move_left(t_game **game)
{
	(*game)->img->pirate->instances[0].x -= 64;
	ft_collectible(game);
	(*game)->score->count_steps++;
	ft_printf("\nCount Steps: %i", (*game)->score->count_steps);
	if ((*game)->score->count_collectible == 0)
		ft_go_exit(game);
}

void	ft_move_right(t_game **game)
{
	(*game)->img->pirate->instances[0].x += 64;
	ft_collectible(game);
	(*game)->score->count_steps++;
	ft_printf("\nCount Steps: %i", (*game)->score->count_steps);
	if ((*game)->score->count_collectible == 0)
		ft_go_exit(game);
}
