/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ckeck_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:22:26 by gde-sa            #+#    #+#             */
/*   Updated: 2024/01/22 11:20:31 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../libft/libft.h"

int	check_extension(char *str)
{
	const char			*extension = ".ber";
	unsigned int		i;
	int					len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len] == '.')
			break ;
		len--;
	}
	i = 0;
	while (str[len] == extension[i])
	{
		if (str[len] == '\0' && extension[i] == '\0')
			return (0);
		i++;
		len++;
	}
	return ((unsigned char)str[len] - (unsigned char)extension[i]);
}

void	ft_validation_args(int argc, char **argv)
{
	if (argc == 1)
		exit(ft_printf("Error\nArguments smaller than expected"));
	else if (argc > 2)
		exit(ft_printf("Error\nArguments larger than expected"));
	else if (!(check_extension(argv[1]) == 0))
		exit(ft_printf("Error\nInvalid extension"));
}
