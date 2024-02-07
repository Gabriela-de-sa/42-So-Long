/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:54:54 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/06 13:01:17 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../../libft/libft.h"

void	ft_enemy(t_game **game)
{
	int	player_x;
	int	player_y;
	int	i;

	i = 0;
	while (i < (*game)->score->count_enemy)
	{
		player_x = (*game)->img->pirate->instances[0].x;
		player_y = (*game)->img->pirate->instances[0].y;
		if (player_x == (*game)->img->enemy->instances[i].x \
			&& player_y == (*game)->img->enemy->instances[i].y)
		{
			ft_printf("\nTouched the enemy. End of the game!!!");
			mlx_close_window((*game)->mlx);
		}
		i++;
	}
}
