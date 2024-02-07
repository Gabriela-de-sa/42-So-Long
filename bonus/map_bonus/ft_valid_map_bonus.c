/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:46:40 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/06 14:04:37 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../../libft/libft.h"

void	ft_check_pos(t_game **game)
{
	int	i;
	int	j;

	i = 0;
	while ((*game)->map[i])
	{
		j = 0;
		while ((*game)->map[i][j])
		{
			if ((*game)->map[i][j] == 'P')
			{
				(*game)->x = i;
				(*game)->y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_valid_rectangle(t_game **game)
{
	if ((*game)->cord_x == (*game)->cord_y)
	{
		ft_endgame(game);
		exit(ft_printf("\nError\nMatrix is not a rectangle"));
	}
}

void	ft_valid_number_line(t_game **game)
{
	int	i;
	int	len_line;

	i = 0;
	len_line = 0;
	(*game)->cord_y = ft_strlen_line((*game)->map[i]);
	while ((*game)->map[i])
	{
		len_line = ft_strlen_line((*game)->map[i]);
		if (len_line != (*game)->cord_y)
		{
			ft_endgame(game);
			exit(ft_printf("Error\nInvalid number of columns"));
		}
		i++;
		(*game)->cord_x++;
	}
}

void	ft_check_map(t_game **game)
{
	ft_valid_number_line(game);
	ft_valid_rectangle(game);
	ft_check_walls(game);
	ft_check_pos(game);
	ft_flood_fill(game, (*game)->x, (*game)->y);
	if (!(((*game)->score->count_collectible_copy == 0) || \
	((*game)->score->count_exit_copy == 0)))
	{
		ft_endgame(game);
		exit(ft_printf("\nError\nMap with invalid path"));
	}
}
