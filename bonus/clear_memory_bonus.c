/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:00:13 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/07 11:36:36 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"

void	ft_endgame(t_game **game)
{
	int	i;

	free((*game)->score);
	free((*game)->img);
	free((*game)->texture);
	i = 0;
	while (i < (*game)->cord_x)
	{
		free((*game)->map[i]);
		i++;
	}
	i = 0;
	while (i < (*game)->cord_x)
	{
		free((*game)->map_copy[i]);
		i++;
	}
	free((*game)->map);
	free((*game)->map_copy);
	free(*game);
}

void	ft_message_error(t_game **game)
{
	free((*game)->score);
	free(*game);
	exit(EXIT_FAILURE);
}

void	ft_delete_image(t_game **game)
{
	mlx_delete_image((*game)->mlx, (*game)->img->background);
	mlx_delete_texture((*game)->texture->background_t);
	mlx_delete_image((*game)->mlx, (*game)->img->collectible);
	mlx_delete_texture((*game)->texture->collectible_t);
	mlx_delete_image((*game)->mlx, (*game)->img->exit);
	mlx_delete_texture((*game)->texture->exit_t);
	mlx_delete_image((*game)->mlx, (*game)->img->pirate);
	mlx_delete_texture((*game)->texture->pirate_t);
	mlx_delete_image((*game)->mlx, (*game)->img->tree);
	mlx_delete_texture((*game)->texture->tree_t);
	mlx_delete_texture((*game)->texture->enemy_t);
	mlx_delete_image((*game)->mlx, (*game)->img->enemy);
	mlx_delete_texture((*game)->texture->icon_flag);
	mlx_delete_image((*game)->mlx, (*game)->img->icon_flag);
	mlx_delete_texture((*game)->texture->icon);
	mlx_delete_image((*game)->mlx, (*game)->img->icon);
}
