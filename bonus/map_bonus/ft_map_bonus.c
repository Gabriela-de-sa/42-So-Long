/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:45:26 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/31 19:40:41 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../../libft/libft.h"

char	*ft_strjoin_line(char const *s1, char const *s2)
{
	char	*new_string;
	int		i;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen_line(s1);
	len_s2 = ft_strlen_line(s2);
	if (!s1 && !s2)
		return (NULL);
	new_string = (char *) malloc(len_s1 + len_s2 + 2);
	if (new_string == NULL)
		return (NULL);
	i = -1;
	while (s1 != NULL && s1[++i])
		new_string[i] = s1[i];
	i = 0;
	while (s2 != NULL && s2[i])
	{
		new_string[i + len_s1] = s2[i];
		i++;
	}
	new_string[i + len_s1] = '\0';
	return (new_string);
}

void	ft_create_matrix(char *argv, t_game **game)
{
	int		file;
	char	*line;
	char	*temp2;
	char	*temp;

	file = ft_open_file(argv);
	line = get_next_line(file);
	temp = " ";
	while (find_line_break(line, '\n') && temp != NULL)
	{
		temp = get_next_line(file);
		temp2 = line;
		line = ft_strjoin_line(line, temp);
		free(temp2);
		free(temp);
	}
	(*game)->map = ft_split(line, '\n');
	(*game)->map_copy = ft_split(line, '\n');
	free(line);
}
