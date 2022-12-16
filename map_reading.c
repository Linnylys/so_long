/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:57:16 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/01 23:03:32 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include<stddef.h>

t_tile	**map_alloc(int nb_line, int nb_column)
{
	int		i;
	t_tile	**line;

	line = malloc ((nb_line + 1) * sizeof(t_tile *));
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < nb_line)
	{
		line[i] = malloc(sizeof(t_tile) * (nb_column + 1));
		if (line[i] == NULL)
		{
			free_tab(line, i);
			return (NULL);
		}
		i++;
	}
	line[i] = NULL;
	return (line);
}

int	map_first_reading(t_param *param, char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		flag;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	flag = line_analyse(param, line, 1);
	param -> mapsize.nb_column = ft_strlen_modif(line);
	i = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		flag = line_analyse(param, line, flag);
		i++;
	}
	if (check_nb_item_and_endline(param, i) == 0 || flag == 0)
		return (0);
	param->mapsize.nb_line = i - 1;
	free (line);
	close (fd);
	return (1);
}

int	map_second_reading(t_param *param, char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	param->map = map_alloc(param->mapsize.nb_line, param->mapsize.nb_column);
	fd = open(file, O_RDONLY);
	if (check_file_opening(fd) == 0)
		return (0);
	i = 0;
	while (i < param->mapsize.nb_line)
	{
		line = get_next_line(fd);
		j = 0;
		while (j < param->mapsize.nb_column && line != NULL)
		{
			affect_map(param, line, i, j);
			j++;
		}
		free (line);
		i++;
	}
	line = get_next_line(fd);
	close (fd);
	return (1);
}

int	image_drawing(t_param *pm)
{
	int			i;
	int			j;
	int			isize;
	int			jsize;
	t_image		img;

	i = 0;
	while (i < pm->mapsize.nb_line)
	{
		j = 0;
		while (j < pm->mapsize.nb_column)
		{
			img = drawing_sprite(*pm, i, j);
			jsize = j * BSIZE + 1;
			isize = i * BSIZE;
			mlx_put_image_to_window(pm->mlx, pm->win, img.ptr, jsize, isize);
			if (img.ptr)
				mlx_destroy_image(pm->mlx, img.ptr);
			j++;
		}
		i++;
	}
	return (0);
}
