/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_flood_flill_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:49:20 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/06 12:44:26 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../../libft/libft.h"

void	ft_flood_fill(t_game **game, int x, int y)
{
	if ((*game)->map_copy[x][y] == 'C')
		(*game)->score->count_collectible_copy--;
	if ((*game)->map_copy[x][y] == 'E')
		(*game)->score->count_exit_copy--;
	if ((*game)->map_copy[x][y] == '1' || (*game)->map_copy[x][y] == 'X' ||
		(*game)->map_copy[x][y] == 'I')
		return ;
	(*game)->map_copy[x][y] = 'X';
	ft_flood_fill(game, x - 1, y);
	ft_flood_fill(game, x + 1, y);
	ft_flood_fill(game, x, y + 1);
	ft_flood_fill(game, x, y - 1);
}
