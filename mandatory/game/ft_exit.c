/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:59:16 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/06 12:11:49 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../libft/libft.h"

void	ft_go_exit(t_game **game)
{
	int	player_x;
	int	player_y;

	player_x = (*game)->img->pirate->instances[0].x;
	player_y = (*game)->img->pirate->instances[0].y;
	if (player_x == (*game)->img->exit->instances[0].x \
		&& player_y == (*game)->img->exit->instances[0].y)
	{
		ft_printf("\nCongratulations. End of the game!!!");
		mlx_close_window((*game)->mlx);
	}
}
