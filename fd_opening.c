/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_opening.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:42:20 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/02 22:53:51 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h> 
#include <stdio.h>

int	check_arg(int argc, char **argv)
{
	char	*str;
	int		len;

	if (argc != 2)
	{
		ft_putstr("Error \nInvalid Argument - No or too much Arguments\n");
		return (0);
	}
	str = argv[1];
	len = ft_strlen(str);
	if (len <= 4)
	{
		ft_putstr("Error \nInvalid Argument - Not recognized\n");
		return (0);
	}
	if (str[len - 1] == 'r' && str[len - 2] == 'e')
	{
		if (str[len - 3] == 'b' && str[len - 4] == '.')
			return (1);
	}
	ft_putstr("Error \nInvalid Argument - Not recognized\n");
	return (0);
}

int	file_opening(char *file)
{
	int	fd;

	if (!file)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nFile Opening problem");
		return (0);
	}
	close(fd);
	return (1);
}

int	check_file_opening(int fd)
{
	if (fd == -1)
	{
		ft_putstr("Error\nFile Opening problem\n");
		return (0);
	}
	return (1);
}
