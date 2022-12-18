/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:53:40 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/01 21:51:08 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include<stddef.h>

int	check_line_error_management(int i)
{
	if (i == 0)
	{
		ft_putstr("Error \nInvalid Map - Too Large\n");
		return (0);
	}
	else
	{
		ft_putstr("Error \nInvalid Map - Not Rectangular\n");
		return (0);
	}
}

int	check_border(t_param *param, int line_int, int i, int j)
{
	int	check_border;

	check_border = 0;
	if (i == 0 && line_int != 1)
		check_border = 1;
	if (i == param -> mapsize.nb_line - 1 && line_int != 1)
		check_border = 1;
	if (j == 0 && line_int != 1)
		check_border = 1;
	if (j == param -> mapsize.nb_column - 1 && line_int != 1)
		check_border = 1;
	if (check_border == 1)
		ft_putstr("Error \nInvalid Map - Not surrended exclusively by wall\n");
	return (check_border);
}

t_tile	simple_affect(t_tile map_res, int line_int, int i, int j)
{
	t_tile	res;

	res.type = line_int;
	res.chck_fill = 0;
	res.og_type = map_res.type;
	res.pos.x = i;
	res.pos.y = j;
	return (res);
}

int	affect_map(t_param *param, char *line, int i, int j)
{
	int			line_int;

	line_int = type_convert(line[j]);
	if (check_border(param, line_int, i, j) == 1)
		param->check_border = 0;
	param->map[i][j] = simple_affect(param->map[i][j], line_int, i, j);
	if (i != 0)
		param->map[i][j].up = &(param->map[i - 1][j]);
	if (i != param -> mapsize.nb_line - 1)
		param->map[i][j].down = &(param->map[i + 1][j]);
	if (j != 0)
		param->map[i][j].left = &(param->map[i][j - 1]);
	if (j != param -> mapsize.nb_column - 1)
		param->map[i][j].right = &(param->map[i][j + 1]);
	if (line_int == 4)
	{
		param -> play.tile = &(param->map[i][j]);
		param -> play.prev_tile = &(param->map[i][j]);
	}
	return (0);
}
