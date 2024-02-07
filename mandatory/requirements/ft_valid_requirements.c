/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_requirements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:05 by gde-sa            #+#    #+#             */
/*   Updated: 2024/01/23 12:38:54 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
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
		&& ((*game)->score->count_exit == 1)))
	{
		ft_return_score(game);
		ft_message_error(game);
	}
	close(file);
}
