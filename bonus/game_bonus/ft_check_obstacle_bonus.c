/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_obstacle_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:56:27 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/06 13:23:48 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../../libft/libft.h"

int	ft_obstacle_up(t_game **game)
{
	int	i;
	int	tree_x;
	int	tree_y;
	int	player_x;
	int	player_y;

	i = 0;
	player_x = (*game)->img->pirate->instances[0].x;
	player_y = (*game)->img->pirate->instances[0].y;
	while (i < (*game)->score->count_tree)
	{
		tree_x = (*game)->img->tree->instances[i].x;
		tree_y = (*game)->img->tree->instances[i].y;
		if (player_x == tree_x && player_y - 64 == tree_y)
			return (1);
		i++;
	}
	return (0);
}

int	ft_obstacle_down(t_game **game)
{
	int	i;
	int	tree_x;
	int	tree_y;
	int	player_x;
	int	player_y;

	i = 0;
	player_x = (*game)->img->pirate->instances[0].x;
	player_y = (*game)->img->pirate->instances[0].y;
	while (i < (*game)->score->count_tree)
	{
		tree_x = (*game)->img->tree->instances[i].x;
		tree_y = (*game)->img->tree->instances[i].y;
		if (player_x == tree_x && player_y + 64 == tree_y)
			return (1);
		i++;
	}
	return (0);
}

int	ft_obstacle_left(t_game **game)
{
	int	i;
	int	tree_x;
	int	tree_y;
	int	player_x;
	int	player_y;

	i = 0;
	player_x = (*game)->img->pirate->instances[0].x;
	player_y = (*game)->img->pirate->instances[0].y;
	while (i < (*game)->score->count_tree)
	{
		tree_x = (*game)->img->tree->instances[i].x;
		tree_y = (*game)->img->tree->instances[i].y;
		if (player_x - 64 == tree_x && player_y == tree_y)
			return (1);
		i++;
	}
	return (0);
}

int	ft_obstacle_right(t_game **game)
{
	int	i;
	int	tree_x;
	int	tree_y;
	int	player_x;
	int	player_y;

	i = 0;
	player_x = (*game)->img->pirate->instances[0].x;
	player_y = (*game)->img->pirate->instances[0].y;
	while (i < (*game)->score->count_tree)
	{
		tree_x = (*game)->img->tree->instances[i].x;
		tree_y = (*game)->img->tree->instances[i].y;
		if (player_x + 64 == tree_x && player_y == tree_y)
			return (1);
		i++;
	}
	return (0);
}
