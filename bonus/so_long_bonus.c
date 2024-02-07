/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:54:34 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/06 14:05:25 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
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
	"SO LONG BONUS", false);
	ft_game(&game);
	mlx_loop(game->mlx);
	ft_delete_image(&game);
	mlx_terminate(game->mlx);
	ft_endgame(&game);
}
