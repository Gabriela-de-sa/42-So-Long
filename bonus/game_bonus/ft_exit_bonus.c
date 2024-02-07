/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:54:46 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/06 13:01:54 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
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
