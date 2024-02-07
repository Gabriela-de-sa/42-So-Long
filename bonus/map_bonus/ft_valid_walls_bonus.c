/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_walls_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:48:18 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/06 13:48:59 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../../libft/libft.h"

void	ft_first_last_line(t_game **game)
{
	int	i;

	i = 0;
	while (i < (*game)->cord_y)
	{
		if ((*game)->map[0][i] != '1' \
		|| (*game)->map[(*game)->cord_x - 1][i] != '1')
		{
			ft_endgame(game);
			exit(ft_printf("Error\nmap with invalid wall"));
		}
		i++;
	}
}

void	ft_left_right_side(t_game **game)
{
	int	i;

	i = 0;
	while (i < (*game)->cord_x)
	{
		if ((*game)->map[i][0] != '1' \
		|| (*game)->map[i][(*game)->cord_y - 1] != '1')
		{
			ft_endgame(game);
			exit(ft_printf("Error\nmap with invalid wall"));
		}
		i++;
	}
}

void	ft_check_walls(t_game **game)
{
	ft_first_last_line(game);
	ft_left_right_side(game);
}
