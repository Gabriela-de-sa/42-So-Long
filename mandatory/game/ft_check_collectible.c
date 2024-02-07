/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_collectible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:50:32 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/05 17:56:11 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../libft/libft.h"

void	ft_collectible(t_game **game)
{
	int	player_x;
	int	player_y;
	int	i;

	i = 0;
	while (i < (*game)->score->coll_map)
	{
		player_x = (*game)->img->pirate->instances[0].x;
		player_y = (*game)->img->pirate->instances[0].y;
		if ((*game)->img->collectible->instances[i].enabled == true \
			&& player_x == (*game)->img->collectible->instances[i].x \
			&& player_y == (*game)->img->collectible->instances[i].y)
		{
			(*game)->img->collectible->instances[i].enabled = false;
			(*game)->score->count_collectible--;
		}
		i++;
	}
}
