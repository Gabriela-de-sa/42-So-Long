/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_score.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:27:02 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/05 17:31:41 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../libft/libft.h"

void	ft_return_score(t_game **game)
{
	if ((*game)->score->count_collectible < 1)
		ft_printf("\nError\nThere is no collectible");
	if ((*game)->score->count_player < 1)
		ft_printf("\nError\nThere is no player to play :(");
	if ((*game)->score->count_player > 1)
		ft_printf("\nError\nThere is a clone :0");
	if ((*game)->score->count_exit < 1)
		ft_printf("\nError\nThere is no way out");
	if ((*game)->score->count_exit > 1)
		ft_printf("\nError\nThere is more than one exit");
}

void	ft_validation_caracter(char *buffer, t_game **game, int *count_caracter)
{
	int		i;

	i = 0;
	while (buffer && buffer[i])
	{
		ft_putchar(buffer[i]);
		(*count_caracter)++;
		if (buffer[i] == 'C')
			(*game)->score->count_collectible++;
		if (buffer[i] == 'P')
			(*game)->score->count_player++;
		if (buffer[i] == 'E')
			(*game)->score->count_exit++;
		if (buffer[i] == '1')
			(*game)->score->count_tree++;
		i++;
	}
}

int	ft_score(int file, int *count_caracter, t_game **game)
{
	char	*buffer;

	(*game)->score->count_collectible = 0;
	(*game)->score->count_exit = 0;
	(*game)->score->count_player = 0;
	(*game)->score->count_tree = 0;
	buffer = "";
	while (buffer)
	{
		buffer = get_next_line(file);
		ft_validation_caracter(buffer, game, count_caracter);
		free(buffer);
	}
	(*game)->score->count_collectible_copy = (*game)->score->count_collectible;
	(*game)->score->coll_map = (*game)->score->count_collectible;
	(*game)->score->count_exit_copy = (*game)->score->count_exit;
	return (*count_caracter);
}
