/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_windows.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:22:20 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/06 17:45:30 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../libft/libft.h"

void	ft_image_windows(t_game **game, int i, int j)
{
	if ((*game)->map[i][j] == '1')
		mlx_image_to_window((*game)->mlx, (*game)->img->tree, \
		j * IMG_X, i * IMG_Y);
	if ((*game)->map[i][j] == 'C')
		mlx_image_to_window((*game)->mlx, (*game)->img->collectible, \
		j * IMG_X, i * IMG_Y);
	if ((*game)->map[i][j] == '0')
		mlx_image_to_window((*game)->mlx, (*game)->img->background, \
		j * IMG_X, i * IMG_Y);
	if ((*game)->map[i][j] == 'E')
		mlx_image_to_window((*game)->mlx, (*game)->img->exit, \
		j * IMG_X, i * IMG_Y);
}

void	ft_load_image(t_game **game)
{
	(*game)->texture->background_t = \
	mlx_load_png("textures/background.png");
	(*game)->img->background = mlx_texture_to_image((*game)->mlx, \
	(*game)->texture->background_t);
	(*game)->texture->tree_t = mlx_load_png("textures/wall.png");
	(*game)->img->tree = mlx_texture_to_image((*game)->mlx, \
	(*game)->texture->tree_t);
	(*game)->texture->collectible_t = mlx_load_png("textures/map.png");
	(*game)->img->collectible = mlx_texture_to_image((*game)->mlx, \
	(*game)->texture->collectible_t);
	(*game)->img->background = mlx_texture_to_image((*game)->mlx, \
	(*game)->texture->background_t);
	(*game)->texture->exit_t = mlx_load_png("textures/treasure.png");
	(*game)->img->exit = mlx_texture_to_image((*game)->mlx, \
	(*game)->texture->exit_t);
	(*game)->texture->pirate_t = mlx_load_png("textures/pirate.png");
	(*game)->img->pirate = mlx_texture_to_image((*game)->mlx, \
	(*game)->texture->pirate_t);
	(*game)->texture->icon_flag = mlx_load_png("textures/flag.png");
	(*game)->img->icon_flag = mlx_texture_to_image((*game)->mlx, \
	(*game)->texture->icon_flag);
}

void	ft_windows(t_game **game)
{
	int	i;
	int	j;

	(*game)->img = ft_calloc(1, sizeof(t_image));
	(*game)->texture = ft_calloc(1, sizeof(t_texture));
	ft_load_image(game);
	i = 0;
	while (i < (*game)->cord_x)
	{
		j = 0;
		while (j < (*game)->cord_y)
		{
			mlx_image_to_window((*game)->mlx, (*game)->img->background, \
			j * IMG_X, i * IMG_Y);
			ft_image_windows(game, i, j);
			j++;
		}
		i++;
	}
	mlx_image_to_window((*game)->mlx, (*game)->img->pirate, \
	(*game)->y * IMG_X, (*game)->x * IMG_Y);
	mlx_set_icon((*game)->mlx, (*game)->texture->icon_flag);
}
