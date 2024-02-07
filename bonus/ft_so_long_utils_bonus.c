/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:58:53 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/31 19:48:18 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

int	ft_open_file(char *argv)
{
	int	file;

	file = open(argv, O_RDONLY);
	if (file < 0)
		exit(ft_printf("Error\nUnable to open the file"));
	return (file);
}

size_t	ft_strlen_line(const char *s)
{
	unsigned int	count;

	count = 0;
	while (s != NULL && s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*find_line_break(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (str != NULL && *str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return (str);
	return (0);
}
