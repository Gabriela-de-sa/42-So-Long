/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:56:02 by gde-sa            #+#    #+#             */
/*   Updated: 2024/02/06 16:40:13 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Main function where I call all functions
*/

#include "include/so_long.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_validation_args(argc, argv);
	game = ft_calloc(1, sizeof(t_game));
	game->score = ft_calloc(1, sizeof(t_score));
	ft_check_requirements(argv[1], &game);
	ft_create_matrix(argv[1], &game);
	ft_check_map(&game);
	game->mlx = mlx_init(game->cord_y * 64, game->cord_x * 64, \
	"SO LONG", false);
	ft_game(&game);
	mlx_loop(game->mlx);
	ft_delete_image(&game);
	mlx_terminate(game->mlx);
	ft_endgame(&game);
}
