/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_requirements_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:08:43 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/31 19:29:43 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../../libft/libft.h"

void	ft_check_requirements(char *argv, t_game **game)
{
	int		file;
	int		count_caracter;

	count_caracter = 0;
	file = ft_open_file(argv);
	ft_score(file, &count_caracter, game);
	if (count_caracter < 17)
	{
		ft_printf("Error\nInvalid simple map");
		ft_message_error(game);
	}
	if (!(((*game)->score->count_collectible >= 1) && \
		((*game)->score->count_player == 1) \
		&& ((*game)->score->count_exit == 1)) && \
		((*game)->score->count_enemy >= 1))
	{
		ft_return_score(game);
		ft_message_error(game);
	}
	close(file);
}
